#pragma once
#include "picture.h"
#include <iostream>
using namespace std;

struct Color
{
	int r, g, b;
};

class ImageEditor
{
public:
	ImageEditor(string inFileName);
	void save(string outFileName);
	

	ImageEditor& operator-(); //Invert all colors and return *this (image negative)
	ImageEditor& operator-=(const Color& c); //subract c from all pixels
	ImageEditor& operator+=(const Color& c); //add c to all pixels
	bool operator==(const ImageEditor& ie) const;  //compare to another image
	bool operator!=(const ImageEditor& ie) const;  //compare to another image
	ImageEditor& operator*=(unsigned int n); //expand by factor of n by n

	string asciiOutFileName;
	ImageEditor& asciiArt(unsigned int n);

	ImageEditor& lineDetection(unsigned int n);

private:
	//void swapPixels(int x1, int y1, int x2, int y2);
	Picture pic;
};
