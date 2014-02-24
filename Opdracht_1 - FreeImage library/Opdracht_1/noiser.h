/* ========================================================================== */
/*                                                                            */
/*   noiser.h                                                                 */
/*   (c) 2013 Chanan van Ooijen & Bryan Baan                                  */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */
#include "stdafx.h"
#include "FreeImage.h"

#pragma once
class noiser
{
public:

	//! This method has parameters bitmap (type: FIBITMAP) and color (type: RGBQUAD) and returns a FIBITMAP object
	//
	//! This method will add Salt and Pepper noise on the FIBITMAP object and returns it
	FIBITMAP* saltAndPepper(FIBITMAP* bitmap, RGBQUAD& color);
};

