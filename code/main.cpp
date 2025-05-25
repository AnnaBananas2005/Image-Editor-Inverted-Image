#include <iostream>
#include "ImageEditor-2.h"

int main(){
  ImageEditor editor("pic.png"); //REPLACE THIS WITH YOUR PNG FILE
  -editor;                       //-editor is from Image editor class
  editor.save("output.png");     //After you run 'make run', the inverted image will be in 'output.png'

  return 0;
}
