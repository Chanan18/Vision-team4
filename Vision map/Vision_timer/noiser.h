/* ========================================================================== */
/*                                                                            */
/*   noiser.h                                                                 */
/*   (c) 2013 Chanan van Ooijen & Bryan Baan                                  */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */
#include "Image.h"
#include "exectimer.h"
#include <iostream>
#include <fstream>

#pragma once
class noiser
{
public:

	//! This method has parameters bitmap (type: FIBITMAP) and color (type: RGBQUAD) and returns a FIBITMAP object
	//
	//! This method will add Salt and Pepper noise on the FIBITMAP object and returns it
	void saltAndPepper(Image &sourceImage, Image &destinationImage, int salt);
};

