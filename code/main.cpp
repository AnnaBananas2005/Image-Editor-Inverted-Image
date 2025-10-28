#include <iostream>
#include "ImageEditor-2.h"


int main(){

  ImageEditor editor("pic.png"); //REPLACE THIS WITH YOUR PNG FILE (h:327, w:280)
  -editor;                       //-editor is from Image editor class
  editor.save("output.png");     //After you run 'make run', the inverted image will be in 'output.png'

  editor.asciiArt(1);			  //ASCII ART
  editor.save("outputAscii.png"); //Grayscale image (ASCII will be shown in terminal)

  editor.lineDetection(1);  //Line Detection with Sobel Operator
  editor.save("lineDetectionFileName.png"); 

  return 0;
}
