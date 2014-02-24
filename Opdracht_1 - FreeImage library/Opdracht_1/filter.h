/* ========================================================================== */
/*                                                                            */
/*   filter.h                                                                 */
/*   (c) 2013 Chanan van Ooijen & Bryan Baan                                  */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */
#pragma once
#include "stdafx.h"
#include "FreeImage.h"

#pragma once
class filter
{
public:
	//! This method has parameters bitmap (type: FIBITMAP) and color (type: RGBQUAD) and returns a FIBITMAP object
	//
	//! This method will apply median filter on the FIBITMAP object and returns it
	FIBITMAP* medianFilter(FIBITMAP* bitmap, RGBQUAD& color);

	//! This method has parameters bitmap (type: FIBITMAP) and color (type: RGBQUAD) and returns a FIBITMAP object
	//
	//! This method will apply minimum filter on the FIBITMAP object and returns it
	FIBITMAP* minimumFilter(FIBITMAP* bitma, RGBQUAD& color);

	//! This method has parameters bitmap (type: FIBITMAP) and color (type: RGBQUAD) and returns a FIBITMAP object
	//
	//! This method will apply maximum filter on the FIBITMAP object and returns it
	FIBITMAP* maximumFilter(FIBITMAP* bitma, RGBQUAD& color);
};

