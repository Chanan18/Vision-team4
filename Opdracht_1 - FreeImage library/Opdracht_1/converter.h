/* ========================================================================== */
/*                                                                            */
/*   converter.h                                                              */
/*   (c) 2013 Chanan van Ooijen & Bryan Baan                                  */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */
#include "stdafx.h"
#include "FreeImage.h"

class converter{
private:

public:

	//! This method has parameters bitmap and color and will convert to gray scale
	FIBITMAP* convertToGray(FIBITMAP* bitmap, RGBQUAD& color);

	//! This method has parameters bitmap (type: FIBITMAP) and color (type: RGBQUAD) and returns a FIBITMAP object
	//
	//! This method will set the blue and green channel for each pixel to 0 (red channel stays unchanged) and will return the changed bitmap
	FIBITMAP* convertToRed(FIBITMAP* bitmap, RGBQUAD& color);

	//! This method has parameters bitmap (type: FIBITMAP) and color (type: RGBQUAD) and returns a FIBITMAP object
	//
	//! This method will set the blue and red channel for each pixel to 0 (green channel stays unchanged) and will return the changed bitmap
	FIBITMAP* convertToGreen(FIBITMAP* bitmap, RGBQUAD& color);

	//! This method has parameters bitmap (type: FIBITMAP) and color (type: RGBQUAD) and returns a FIBITMAP object
	//
	//! This method will set the red and green channel for each pixel to 0 (blue channel stays unchanged) and will return the changed bitmap
	FIBITMAP* convertToBlue(FIBITMAP* bitmap, RGBQUAD& color);

};