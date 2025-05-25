#include <iostream>
#include "ImageEditor-2.h"

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


    



            

