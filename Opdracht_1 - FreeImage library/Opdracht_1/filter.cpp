/* ========================================================================== */
/*                                                                            */
/*   filter.cpp                                                               */
/*   (c) 2013 Chanan van Ooijen & Bryan Baan                                  */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */

#include "stdafx.h"
#include "filter.h"
#include <iostream>

FIBITMAP* filter::medianFilter(FIBITMAP* bitmap, RGBQUAD& color){
	FIBITMAP* filtered = FreeImage_Clone(bitmap);
	int HEIGHT = FreeImage_GetHeight(bitmap);
	int WIDTH = FreeImage_GetWidth(bitmap);
	int k;
	BYTE window[9][3];
	BYTE sortArray[9][3];
	for (int i = 1; i < WIDTH-1; i++) {
		//cout << WIDTH << endl;
		for (int j = 1; j < HEIGHT-1; j++) {
			FreeImage_GetPixelColor(bitmap, i-1, j-1, &color);
			window[0][0] = color.rgbBlue;
			window[0][1] = color.rgbGreen;
			window[0][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i, j-1, &color);
			window[1][0] = color.rgbBlue;
			window[1][1] = color.rgbGreen;
			window[1][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i+1, j-1, &color);
			window[2][0] = color.rgbBlue;
			window[2][1] = color.rgbGreen;
			window[2][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i-1, j, &color);
			window[3][0] = color.rgbBlue;
			window[3][1] = color.rgbGreen;
			window[3][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i, j, &color);
			window[4][0] = color.rgbBlue;
			window[4][1] = color.rgbGreen;
			window[4][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i+1, j, &color);
			window[5][0] = color.rgbBlue;
			window[5][1] = color.rgbGreen;
			window[5][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i-1, j+1, &color);
			window[6][0] = color.rgbBlue;
			window[6][1] = color.rgbGreen;
			window[6][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i, j+1, &color);
			window[7][0] = color.rgbBlue;
			window[7][1] = color.rgbGreen;
			window[7][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i+1, j+1, &color);
			window[8][0] = color.rgbBlue;
			window[8][1] = color.rgbGreen;
			window[8][2] = color.rgbRed;
			//int gesorteArray = insertionSort(window);
			BYTE temp[3];
			for (int index = 0; index < 9; index++) {
				temp[0] = window[index][0];
				temp[1] = window[index][1];
				temp[2] = window[index][2];
				BYTE tempAlles = temp[0] + temp[1] + temp[2];
				BYTE windowAlles = window[index - 1][0] + window[index - 1][1] + window[index - 1][2];
				while ((index - 1 >= 0) && (tempAlles < windowAlles)) {
					window[index][0] = window[index - 1][0];
					window[index][1] = window[index - 1][1];
					window[index][2] = window[index - 1][2];
					index--;
				}
				window[index][0] = temp[0];
				window[index][1] = temp[1];
				window[index][2] = temp[2];
			}
			//window[4][0] + window[4][1] + window[4][2] is wat je moet hebben.
			color.rgbBlue = window[4][0];
			color.rgbGreen = window[4][1];
			color.rgbRed = window[4][2];
			FreeImage_SetPixelColor(filtered, i, j, &color);
		}
	}
	return filtered;
}

FIBITMAP* filter::minimumFilter(FIBITMAP* bitmap, RGBQUAD& color){
	FIBITMAP* filtered = FreeImage_Clone(bitmap);
	int HEIGHT = FreeImage_GetHeight(bitmap);
	int WIDTH = FreeImage_GetWidth(bitmap);
	int k;
	BYTE window[9][3];
	BYTE sortArray[9][3];
	for (int i = 1; i < WIDTH - 1; i++) {
		//cout << WIDTH << endl;
		for (int j = 1; j < HEIGHT - 1; j++) {
			FreeImage_GetPixelColor(bitmap, i - 1, j - 1, &color);
			window[0][0] = color.rgbBlue;
			window[0][1] = color.rgbGreen;
			window[0][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i, j - 1, &color);
			window[1][0] = color.rgbBlue;
			window[1][1] = color.rgbGreen;
			window[1][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i + 1, j - 1, &color);
			window[2][0] = color.rgbBlue;
			window[2][1] = color.rgbGreen;
			window[2][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i - 1, j, &color);
			window[3][0] = color.rgbBlue;
			window[3][1] = color.rgbGreen;
			window[3][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i, j, &color);
			window[4][0] = color.rgbBlue;
			window[4][1] = color.rgbGreen;
			window[4][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i + 1, j, &color);
			window[5][0] = color.rgbBlue;
			window[5][1] = color.rgbGreen;
			window[5][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i - 1, j + 1, &color);
			window[6][0] = color.rgbBlue;
			window[6][1] = color.rgbGreen;
			window[6][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i, j + 1, &color);
			window[7][0] = color.rgbBlue;
			window[7][1] = color.rgbGreen;
			window[7][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i + 1, j + 1, &color);
			window[8][0] = color.rgbBlue;
			window[8][1] = color.rgbGreen;
			window[8][2] = color.rgbRed;
			//int gesorteArray = insertionSort(window);
			BYTE temp[3];
			for (int index = 0; index < 9; index++) {
				temp[0] = window[index][0];
				temp[1] = window[index][1];
				temp[2] = window[index][2];
				BYTE tempAlles = temp[0] + temp[1] + temp[2];
				BYTE windowAlles = window[index - 1][0] + window[index - 1][1] + window[index - 1][2];
				while ((index - 1 >= 0) && (tempAlles < windowAlles)) {
					window[index][0] = window[index - 1][0];
					window[index][1] = window[index - 1][1];
					window[index][2] = window[index - 1][2];
					index--;
				}
				window[index][0] = temp[0];
				window[index][1] = temp[1];
				window[index][2] = temp[2];
			}
			//window[4][0] + window[4][1] + window[4][2] is wat je moet hebben.
			color.rgbBlue = window[1][0];
			color.rgbGreen = window[1][1];
			color.rgbRed = window[1][2];
			FreeImage_SetPixelColor(filtered, i, j, &color);
		}
	}
	return filtered;
}

FIBITMAP* filter::maximumFilter(FIBITMAP* bitmap, RGBQUAD& color){
	FIBITMAP* filtered = FreeImage_Clone(bitmap);
	int HEIGHT = FreeImage_GetHeight(bitmap);
	int WIDTH = FreeImage_GetWidth(bitmap);
	int k;
	BYTE window[9][3];
	BYTE sortArray[9][3];
	for (int i = 1; i < WIDTH - 1; i++) {
		//cout << WIDTH << endl;
		for (int j = 1; j < HEIGHT - 1; j++) {
			FreeImage_GetPixelColor(bitmap, i - 1, j - 1, &color);
			window[0][0] = color.rgbBlue;
			window[0][1] = color.rgbGreen;
			window[0][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i, j - 1, &color);
			window[1][0] = color.rgbBlue;
			window[1][1] = color.rgbGreen;
			window[1][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i + 1, j - 1, &color);
			window[2][0] = color.rgbBlue;
			window[2][1] = color.rgbGreen;
			window[2][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i - 1, j, &color);
			window[3][0] = color.rgbBlue;
			window[3][1] = color.rgbGreen;
			window[3][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i, j, &color);
			window[4][0] = color.rgbBlue;
			window[4][1] = color.rgbGreen;
			window[4][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i + 1, j, &color);
			window[5][0] = color.rgbBlue;
			window[5][1] = color.rgbGreen;
			window[5][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i - 1, j + 1, &color);
			window[6][0] = color.rgbBlue;
			window[6][1] = color.rgbGreen;
			window[6][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i, j + 1, &color);
			window[7][0] = color.rgbBlue;
			window[7][1] = color.rgbGreen;
			window[7][2] = color.rgbRed;
			FreeImage_GetPixelColor(bitmap, i + 1, j + 1, &color);
			window[8][0] = color.rgbBlue;
			window[8][1] = color.rgbGreen;
			window[8][2] = color.rgbRed;
			//int gesorteArray = insertionSort(window);
			BYTE temp[3];
			for (int index = 0; index < 9; index++) {
				temp[0] = window[index][0];
				temp[1] = window[index][1];
				temp[2] = window[index][2];
				BYTE tempAlles = temp[0] + temp[1] + temp[2];
				BYTE windowAlles = window[index - 1][0] + window[index - 1][1] + window[index - 1][2];
				while ((index - 1 >= 0) && (tempAlles < windowAlles)) {
					window[index][0] = window[index - 1][0];
					window[index][1] = window[index - 1][1];
					window[index][2] = window[index - 1][2];
					index--;
				}
				window[index][0] = temp[0];
				window[index][1] = temp[1];
				window[index][2] = temp[2];
			}
			//window[4][0] + window[4][1] + window[4][2] is wat je moet hebben.
			color.rgbBlue = window[7][0];
			color.rgbGreen = window[7][1];
			color.rgbRed = window[7][2];
			FreeImage_SetPixelColor(filtered, i, j, &color);
		}
	}
	return filtered;
}


