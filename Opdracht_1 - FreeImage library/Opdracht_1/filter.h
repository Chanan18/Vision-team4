#pragma once
#include "stdafx.h"
#include "FreeImage.h"

#pragma once
class filter
{
public:
	FIBITMAP* medianFilter(FIBITMAP* bitmap, RGBQUAD& color);
	FIBITMAP* minimumFilter(FIBITMAP* bitma, RGBQUAD& color);
	FIBITMAP* maximumFilter(FIBITMAP* bitma, RGBQUAD& color);
};

