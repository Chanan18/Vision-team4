// Opdracht_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include "FreeImage.h"
#include "converter.h"
#include "histogram.h"
#include "noiser.h"
#include "filter.h"

typedef unsigned char Byte;
using namespace std;

int main(int argc, char* argv[])
{
	converter c;
	histogram h;
	noiser n;
	filter f;
	cout << "Enter filename with max 30 characters:" << endl;
	char s[30];
	cin.getline(s, 30);
	FreeImage_Initialise();

	FIBITMAP* bitmap = FreeImage_Load(FIF_BMP, s, BMP_DEFAULT);
	RGBQUAD color;

	if (!bitmap){
		exit(1);
	}

	FIBITMAP* gray_bitmap = FreeImage_Clone(bitmap);
	gray_bitmap = c.convertToGray(gray_bitmap, color);
	
	FIBITMAP* red_bitmap = FreeImage_Clone(bitmap);
	red_bitmap = c.convertToRed(red_bitmap, color);

	FIBITMAP* green_bitmap = FreeImage_Clone(bitmap);
	green_bitmap = c.convertToGreen(green_bitmap, color);

	FIBITMAP* blue_bitmap = FreeImage_Clone(bitmap);
	blue_bitmap = c.convertToBlue(blue_bitmap, color);

	FIBITMAP* salt_and_pepper_bitmap = FreeImage_Clone(bitmap);
	cout << "Enter % salt&pepper noise:" << endl;
	int salt;
	std::cin >> salt;
	salt_and_pepper_bitmap = n.saltAndPepper(salt_and_pepper_bitmap, color, salt);

	FIBITMAP* median_bitmap = FreeImage_Clone(salt_and_pepper_bitmap);
	median_bitmap = f.medianFilter(median_bitmap, color);

	FIBITMAP* minimum_bitmap = FreeImage_Clone(salt_and_pepper_bitmap);
	minimum_bitmap = f.minimumFilter(minimum_bitmap, color);

	FIBITMAP* maximum_bitmap = FreeImage_Clone(salt_and_pepper_bitmap);
	maximum_bitmap = f.maximumFilter(maximum_bitmap, color);

	char grey_output[30] = "grey_";
	strcat(grey_output, s);
	std::cout << grey_output << std::endl;

	if (FreeImage_Save(FIF_BMP, gray_bitmap, grey_output, 0))
		cout << "Succesfully saved gray image" << endl;

	char red_channel_output[30] = "R_";
	strcat(red_channel_output, s);
	std::cout << red_channel_output << std::endl;

	if (FreeImage_Save(FIF_BMP, red_bitmap, red_channel_output, 0))
		cout << "Succesfully saved red channel image" << endl;

	char green_channel_output[30] = "G_";
	strcat(green_channel_output, s);
	std::cout << green_channel_output << std::endl;

	if (FreeImage_Save(FIF_BMP, green_bitmap, green_channel_output, 0))
		cout << "Succesfully saved green channel image" << endl;

	char blue_channel_output[30] = "B_";
	strcat(blue_channel_output, s);
	std::cout << blue_channel_output << std::endl;

	if (FreeImage_Save(FIF_BMP, blue_bitmap, blue_channel_output, 0))
		cout << "Succesfully saved blue channel image" << endl;

	char saltAndPepper_output[30] = "noise_";
	strcat(saltAndPepper_output, s);
	std::cout << saltAndPepper_output << std::endl;

	if (FreeImage_Save(FIF_BMP, salt_and_pepper_bitmap, saltAndPepper_output, 0))
		cout << "Succesfully saved salt and pepper image" << endl;

	char median_filter_output[30] = "median_";
	strcat(median_filter_output, s);
	std::cout << median_filter_output << std::endl;

	if (FreeImage_Save(FIF_BMP, median_bitmap, median_filter_output, 0))
		cout << "Succesfully saved median filter image" << endl;

	char min_filter_output[30] = "min_";
	strcat(min_filter_output, s);
	std::cout << min_filter_output << std::endl;

	if (FreeImage_Save(FIF_BMP, minimum_bitmap, min_filter_output, 0))
		cout << "Succesfully saved minimum filter image" << endl;

	char max_filter_output[30] = "max_";
	strcat(max_filter_output, s);
	std::cout << max_filter_output << std::endl;

	if (FreeImage_Save(FIF_BMP, maximum_bitmap, max_filter_output, 0))
		cout << "Succesfully saved maximum filter image" << endl;


	h.createHistogram256(gray_bitmap, s);
	h.createHistogram10(gray_bitmap);

	h.createHistogram10Red(red_bitmap);
	h.createHistogram10Green(green_bitmap);
	h.createHistogram10Blue(blue_bitmap);

	FreeImage_Unload(gray_bitmap);
	FreeImage_Unload(red_bitmap);
	FreeImage_Unload(green_bitmap);
	FreeImage_Unload(blue_bitmap);
	FreeImage_Unload(salt_and_pepper_bitmap);
	FreeImage_Unload(median_bitmap);
	FreeImage_Unload(minimum_bitmap);
	FreeImage_Unload(maximum_bitmap);

	std::cin.get();
	return 0;
}

