/* ========================================================================== */
/*                                                                            */
/*   Equalize.h                                                               */
/*   (c) 2013 Chanan van Ooijen & Bryan Baan                                  */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */
#ifndef Equalize_H
#define Equalize_H
#include "Image.h"
#include "exectimer.h"
#include <iostream>
#include <fstream>


class Equalize {
private:
private:
	// Define BaseTimer object
	BaseTimer* bt;
public:
	// Default constructor
	Equalize();

	// Destructor
	~Equalize();

	// This method has parameters a source image, a destination image
	//
	// This method will create an equalized image from sourceImage and store it in destionationImage
	void CreateEqualizedImage(Image &sourceImage, Image &destinationImage);
};

#endif