/* ========================================================================== */
/*                                                                            */
/*   histogram.cpp                                                            */
/*   (c) 2013 Chanan van Ooijen & Bryan Baan                                  */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */

#include "stdafx.h"
#include "histogram.h"
#include <iostream>

void histogram::createHistogram256(FIBITMAP* gray_bitmap){
	int HEIGHT = FreeImage_GetHeight(gray_bitmap);
	int WIDTH = FreeImage_GetWidth(gray_bitmap);
	int totalPixels = 0;
	float normalize;
	RGBQUAD color;
	ofstream histogramFile;
	ofstream equalized_histogramFile;
	int histogram_array[256];
	histogramFile.open("histogram256.csv", ios::out);
	equalized_histogramFile.open("equalized_histogram256.csv", ios::out);

	for (int i = 0; i < 256; i++){
		histogram_array[i] = 0;
	}

	for (int i = 0; i < WIDTH; i++) {
		//cout << WIDTH << endl;
		for (int j = 0; j < HEIGHT; j++) {
			//cout << HEIGHT << endl;
			FreeImage_GetPixelColor(gray_bitmap, i, j, &color);
			histogram_array[color.rgbRed] ++;
		}
	}

	for (int i = 0; i < 256; i++)
		totalPixels += histogram_array[i];

	for (int i = 0; i < 256; i++){
		normalize = histogram_array[i] / float(totalPixels);
		histogramFile << i << "," << normalize << endl;
	}

	// NOW COMES EQUALIZATION PART!
	//
	//
	//
	//
	float alpha = 255 / float(totalPixels);
	float equalized_histogram_array[256];
	char output[30] = "equalized.bmp";

	equalized_histogram_array[0] = histogram_array[0] * alpha;

	//Creating the histogram, could be removed
	for (int i = 1; i < 256; i++){
		equalized_histogram_array[i] = equalized_histogram_array[i - 1] + (histogram_array[i] * alpha);
		//::cout << cumulative_histogram_array[i] << std::endl;
		equalized_histogramFile << i << "," << equalized_histogram_array[i] << endl;
	}

	FIBITMAP* equalized_picture = FreeImage_Clone(gray_bitmap);
	RGBQUAD colorr;

	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			FreeImage_GetPixelColor(equalized_picture, i, j, &colorr);
			colorr.rgbRed = colorr.rgbGreen = colorr.rgbBlue = equalized_histogram_array[colorr.rgbRed];
			FreeImage_SetPixelColor(equalized_picture, i, j, &colorr);
		}
	}

	if (FreeImage_Save(FIF_BMP, equalized_picture, "equalized_picture.bmp", 0)){
		cout << "Succesfully saved lolololol!!!!!!" << endl;
	}
}

void histogram::createHistogram10(FIBITMAP* gray_bitmap){
	int HEIGHT = FreeImage_GetHeight(gray_bitmap);
	int WIDTH = FreeImage_GetWidth(gray_bitmap);
	int totalPixels = 0;
	float normalize;
	RGBQUAD color;
	ofstream histogramFile;
	int histogram_array[10];
	histogramFile.open("histogram10.csv", ios::out);

	for (int i = 0; i < 10; i++){
		histogram_array[i] = 0;
	}

	for (int i = 0; i < WIDTH; i++) {
		//cout << WIDTH << endl;
		for (int j = 0; j < HEIGHT; j++) {
			//cout << HEIGHT << endl;
			FreeImage_GetPixelColor(gray_bitmap, i, j, &color);
			histogram_array[(int)((color.rgbRed * 10) / 256)] ++;
			//“(int) ((intensiteit * 10) / 256)
		}
	}

	for (int i = 0; i < 10; i++)
		totalPixels += histogram_array[i];

	for (int i = 0; i < 10; i++){
		normalize = histogram_array[i] / float(totalPixels);
		histogramFile << i << "," << normalize << endl;
	}
}


void histogram::createHistogram10Red(FIBITMAP* red_bitmap){
	int HEIGHT = FreeImage_GetHeight(red_bitmap);
	int WIDTH = FreeImage_GetWidth(red_bitmap);
	int totalPixels = 0;
	float normalize;
	RGBQUAD color;
	ofstream histogramFile;
	int histogram_array[10];
	histogramFile.open("histogram10Red.csv", ios::out);

	for (int i = 0; i < 10; i++){
		histogram_array[i] = 0;
	}

	for (int i = 0; i < WIDTH; i++) {
		//cout << WIDTH << endl;
		for (int j = 0; j < HEIGHT; j++) {
			//cout << HEIGHT << endl;
			FreeImage_GetPixelColor(red_bitmap, i, j, &color);
			histogram_array[(int)((color.rgbRed * 10) / 256)] ++;
			//“(int) ((intensiteit * 10) / 256)
		}
	}

	for (int i = 0; i < 10; i++)
		totalPixels += histogram_array[i];

	for (int i = 0; i < 10; i++){
		normalize = histogram_array[i] / float(totalPixels);
		histogramFile << i << "," << normalize << endl;
	}
}


void histogram::createHistogram10Green(FIBITMAP* green_bitmap){
	int HEIGHT = FreeImage_GetHeight(green_bitmap);
	int WIDTH = FreeImage_GetWidth(green_bitmap);
	int totalPixels = 0;
	float normalize;
	RGBQUAD color;
	ofstream histogramFile;
	int histogram_array[10];
	histogramFile.open("histogram10Green.csv", ios::out);

	for (int i = 0; i < 10; i++){
		histogram_array[i] = 0;
	}

	for (int i = 0; i < WIDTH; i++) {
		//cout << WIDTH << endl;
		for (int j = 0; j < HEIGHT; j++) {
			//cout << HEIGHT << endl;
			FreeImage_GetPixelColor(green_bitmap, i, j, &color);
			histogram_array[(int)((color.rgbGreen * 10) / 256)] ++;
			//“(int) ((intensiteit * 10) / 256)
		}
	}

	for (int i = 0; i < 10; i++)
		totalPixels += histogram_array[i];

	for (int i = 0; i < 10; i++){
		normalize = histogram_array[i] / float(totalPixels);
		histogramFile << i << "," << normalize << endl;
	}
}



void histogram::createHistogram10Blue(FIBITMAP* blue_bitmap){
	int HEIGHT = FreeImage_GetHeight(blue_bitmap);
	int WIDTH = FreeImage_GetWidth(blue_bitmap);
	int totalPixels = 0;
	float normalize;
	RGBQUAD color;
	ofstream histogramFile;
	int histogram_array[10];
	histogramFile.open("histogram10Blue.csv", ios::out);

	for (int i = 0; i < 10; i++){
		histogram_array[i] = 0;
	}

	for (int i = 0; i < WIDTH; i++) {
		//cout << WIDTH << endl;
		for (int j = 0; j < HEIGHT; j++) {
			//cout << HEIGHT << endl;
			FreeImage_GetPixelColor(blue_bitmap, i, j, &color);
			histogram_array[(int)((color.rgbBlue * 10) / 256)] ++;
			//“(int) ((intensiteit * 10) / 256)
		}
	}

	for (int i = 0; i < 10; i++)
		totalPixels += histogram_array[i];

	for (int i = 0; i < 10; i++){
		normalize = histogram_array[i] / float(totalPixels);
		histogramFile << i << "," << normalize << endl;
	}
}

