/* ========================================================================== */
/*                                                                            */
/*   converter.cpp                                                            */
/*   (c) 2013 Chanan van Ooijen & Bryan Baan                                  */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */

#include "stdafx.h"
#include "converter.h"

FIBITMAP* converter::convertToGray(FIBITMAP* bitmap, RGBQUAD& color){
	int HEIGHT = FreeImage_GetHeight(bitmap);
	int WIDTH = FreeImage_GetWidth(bitmap);
	double grayValue;

	for (int i = 0; i < WIDTH; i++) {
		//cout << WIDTH << endl;
		for (int j = 0; j < HEIGHT; j++) {
			//cout << HEIGHT << endl;
			FreeImage_GetPixelColor(bitmap, i, j, &color);
			grayValue = (color.rgbRed * 0.30) +
				(color.rgbGreen * 0.59) +
				(color.rgbBlue * 0.11);
			color.rgbRed = color.rgbGreen = color.rgbBlue = grayValue;
			FreeImage_SetPixelColor(bitmap, i, j, &color);
		}
	}

	return bitmap;
}

FIBITMAP* converter::convertToRed(FIBITMAP* bitmap, RGBQUAD& color){
	int HEIGHT = FreeImage_GetHeight(bitmap);
	int WIDTH = FreeImage_GetWidth(bitmap);

	for (int i = 0; i < WIDTH; i++) {
		//cout << WIDTH << endl;
		for (int j = 0; j < HEIGHT; j++) {
			//cout << HEIGHT << endl;
			FreeImage_GetPixelColor(bitmap, i, j, &color);
			color.rgbGreen = color.rgbBlue = 0;
			FreeImage_SetPixelColor(bitmap, i, j, &color);
		}
	}

	return bitmap;
}

FIBITMAP* converter::convertToGreen(FIBITMAP* bitmap, RGBQUAD& color){
	int HEIGHT = FreeImage_GetHeight(bitmap);
	int WIDTH = FreeImage_GetWidth(bitmap);

	for (int i = 0; i < WIDTH; i++) {
		//cout << WIDTH << endl;
		for (int j = 0; j < HEIGHT; j++) {
			//cout << HEIGHT << endl;
			FreeImage_GetPixelColor(bitmap, i, j, &color);
			color.rgbRed = color.rgbBlue = 0;
			FreeImage_SetPixelColor(bitmap, i, j, &color);
		}
	}

	return bitmap;
}

FIBITMAP* converter::convertToBlue(FIBITMAP* bitmap, RGBQUAD& color){
	int HEIGHT = FreeImage_GetHeight(bitmap);
	int WIDTH = FreeImage_GetWidth(bitmap);

	for (int i = 0; i < WIDTH; i++) {
		//cout << WIDTH << endl;
		for (int j = 0; j < HEIGHT; j++) {
			//cout << HEIGHT << endl;
			FreeImage_GetPixelColor(bitmap, i, j, &color);
			color.rgbGreen = color.rgbRed = 0;
			FreeImage_SetPixelColor(bitmap, i, j, &color);
		}
	}

	return bitmap;
}