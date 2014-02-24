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

	//! This method has parameters bitmap and color and will convert to gray scale
	FIBITMAP* convertToRed(FIBITMAP* bitmap, RGBQUAD& color);

	//! This method has parameters bitmap and color and will convert to gray scale
	FIBITMAP* convertToGreen(FIBITMAP* bitmap, RGBQUAD& color);

	//! This method has parameters bitmap and color and will convert to gray scale
	FIBITMAP* convertToBlue(FIBITMAP* bitmap, RGBQUAD& color);

};