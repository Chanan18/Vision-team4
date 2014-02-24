#include "stdafx.h"
#include "noiser.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>


FIBITMAP* noiser::saltAndPepper(FIBITMAP* bitmap, RGBQUAD& color) {
	int HEIGHT = FreeImage_GetHeight(bitmap);
	int WIDTH = FreeImage_GetWidth(bitmap);
	srand(time(0));
	int i;
	int j;
	int condition = 0;
	int moduloshiznit = (HEIGHT * WIDTH) / 100;
	while (condition <= ((HEIGHT * WIDTH) / 128))  {
		i = rand() % WIDTH;
		j = rand() % HEIGHT;
		FreeImage_GetPixelColor(bitmap, i, j, &color);
		if (condition % 2 == 0) {
			color.rgbRed = color.rgbGreen = color.rgbBlue = 0;
		} else {
			color.rgbRed = color.rgbGreen = color.rgbBlue = 255;
		}
		
		FreeImage_SetPixelColor(bitmap, i, j, &color);
		condition++;

	}
	return bitmap;
}
