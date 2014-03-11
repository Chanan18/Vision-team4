/* ========================================================================== */
/*                                                                            */
/*   GrayScale.h                                                              */
/*   (c) 2013 Chanan van Ooijen & Bryan Baan                                  */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */
#ifndef GrayScale_H
#define GrayScale_H
#include "Image.h"
#include "exectimer.h"
#include <iostream>

class GrayScale {
private:
	// Define BaseTimer object
	BaseTimer* bt;
public:
	// Default constructor
	GrayScale();

	// Destructor
	~GrayScale();

	// This method has parameters a source image, a destination image
	//
	// This method will create a gray scaled image from sourceImage and store it in destionationImage
	void CreateGrayScaleImage(Image &sourceImage, Image &destinationImage);
};

#endif