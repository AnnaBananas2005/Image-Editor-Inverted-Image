#include <iostream>
#include <fstream>
#include "ImageEditor-2.h"
#include <cmath> //for line detection

using namespace std;

ImageEditor::ImageEditor(string inFileName) : pic(inFileName) {}
        
void ImageEditor::save(string outFileName){  
    pic.save(outFileName);
}
        
ImageEditor& ImageEditor::operator-(){   
    for (int x = 0; x < pic.height(); x++){
        for (int y = 0; y < pic.width(); y++){
            int r = 255 - pic.red(y,x); 
            int g = 255 - pic.green(y,x);
            int b = 255 - pic.blue(y,x);
            pic.set(y,x,r,g,b);
        }
    }
    return *this;
}
        
ImageEditor& ImageEditor::operator-=(const Color& c){ 
    for (int x = 0; x < pic.height(); x++){
        for (int y = 0; y < pic.width(); y++){
            int r = max(0, pic.red(y,x) - c.r);
            int g = max(0, pic.green(y,x) - c.g);
            int b = max(0, pic.blue(y,x) - c.b);
            pic.set(y,x,r,g,b);
        }
    }
    return *this;
}
        
ImageEditor& ImageEditor::operator+=(const Color& c){
    for (int x = 0; x < pic.height(); x++){
        for (int y = 0; y < pic.width(); y++){
            int r = min(255, pic.red(y,x) + c.r);
            int g = min(255, pic.green(y,x) + c.g);
            int b = min(255, pic.blue(y,x) + c.b);
            pic.set(y,x,r,g,b);
        }
    }
    return *this;

}
        
bool ImageEditor::operator==(const ImageEditor& ie) const{ 
    if (pic.height() != ie.pic.height() || pic.width() != ie.pic.width()){
        return false;
    }
    for (int x = 0; x < pic.height(); x++){ 
        for (int y = 0; y < pic.width(); y++){
            if(pic.red(y,x) != ie.pic.red(y,x) || pic.green(y,x) != ie.pic.green(y,x) || pic.blue(y,x) != ie.pic.blue(y,x))
                return false;
        }
    }
    return true;

}
        
bool ImageEditor::operator!=(const ImageEditor& ie) const{ 
    return !(*this == ie);
}
        
ImageEditor& ImageEditor::operator*=(unsigned int n){
    if (n < 1 || n > 10){
        throw runtime_error("ERROR!");
    }

    Picture picOut(pic.width() * n, pic.height() * n); 
    
    for(int x = 0; x < pic.width(); x++){ 
        for(int y = 0; y < pic.height(); y++){
            int red = pic.red(x,y);      
            int green = pic.green(x,y);
            int blue = pic.blue(x,y);
        
            for(unsigned int xOut = 0; xOut < n; xOut++){
                for(unsigned int yOut = 0; yOut < n; yOut++){
                    picOut.set(x * n + xOut, y * n + yOut, red,green,blue); 
                }
            }
        }
    }
    pic = picOut;
    return *this;    
}

//Extra credit
//Density: https://www.astoundingscripts.com/art/create-your-own-ascii-art-palettes-densitysort/
//^ Used short (opposite) 

ImageEditor& ImageEditor::asciiArt(unsigned int n) {
    Picture picOut(pic.width() * n, pic.height() * n);
    Picture grayscale = pic.grays();
    //string asciiLetters = ".:-=+*#%@"; Inverted
    string asciiLetters = "@%#*+=-:.";

    for (int x = 0; x < pic.height(); x += 1) {
        string row = "";
        for (int y = 0; y < pic.width(); y += 1) {
            int brightness = grayscale.red(y, x);
            int i = (brightness * (asciiLetters.length() - 1)) / 255;  
            row += asciiLetters[i];
            int value = (i * 255) / (asciiLetters.length() - 1);

            for (unsigned int xOut = 0; xOut < n; xOut++) {
                for (unsigned int yOut = 0; yOut < n; yOut++) {
                    picOut.set(y * n + yOut, x * n + xOut, value, value, value);
                }
            }
        }
        cout << row << endl;
    }
    pic = picOut;

    return *this;

}

//Extra Credit 2: Line Detection by Sobel Algorithm/Sobel Operator
//https://en.wikipedia.org/wiki/Sobel_operator

ImageEditor& ImageEditor::lineDetection(unsigned int n) {
    Picture picOut(pic.width() * n, pic.height() * n);

    Picture grayscale = pic.grays(); 
    int matrixGx[3][3] = {
        {-1,0,1},
        {-2,0,2},
        {-1,0,1}
    };
    int matrixGy[3][3] = {
        {-1,-2,-1},
        {0,0,0},
        {1,2,1}

    };

    for (int x = 0; x < pic.width(); x++) {
        for (int y = 0; y < pic.height(); y++) {

            int Gx = 0;
            int Gy = 0;

            for (int i = -1; i <= +1; i++) {
                for (int j = -1; j <= +1; j++) {
                    int brightness = grayscale.red(x + i, y + j);
                    Gx += matrixGx[i + 1][j + 1] * brightness;
                    Gy += matrixGy[i + 1][j + 1] * brightness;

                }
            }
            double magnitude = sqrt(pow(Gx, 2.0) + pow(Gy, 2.0));
            double theta = atan2(Gy, Gx); 
            double result = (magnitude > 255) ? 255 : magnitude; 
            picOut.set(x, y, result, result, result);
        }
    }

    pic = picOut;
    return *this;

}


    



            

