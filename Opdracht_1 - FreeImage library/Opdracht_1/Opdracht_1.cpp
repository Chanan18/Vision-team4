// Opdracht_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
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

	//FIBITMAP* red_channel_bitmap = FreeImage_Clone(bitmap);
	//red_channel_bitmap

	FIBITMAP* gray_bitmap = FreeImage_Clone(bitmap);
	gray_bitmap = c.convertToGray(gray_bitmap, color);
	
	FIBITMAP* red_bitmap = FreeImage_Clone(bitmap);
	red_bitmap = c.convertToRed(red_bitmap, color);

	FIBITMAP* green_bitmap = FreeImage_Clone(bitmap);
	green_bitmap = c.convertToGreen(green_bitmap, color);

	FIBITMAP* blue_bitmap = FreeImage_Clone(bitmap);
	blue_bitmap = c.convertToBlue(blue_bitmap, color);

	FIBITMAP* salt_and_pepper_bitmap = FreeImage_Clone(bitmap);
	salt_and_pepper_bitmap = n.saltAndPepper(salt_and_pepper_bitmap, color);

	FIBITMAP* median_bitmap = FreeImage_Clone(salt_and_pepper_bitmap);
	median_bitmap = f.medianFilter(median_bitmap, color);

	FIBITMAP* minimum_bitmap = FreeImage_Clone(salt_and_pepper_bitmap);
	minimum_bitmap = f.minimumFilter(minimum_bitmap, color);

	FIBITMAP* maximum_bitmap = FreeImage_Clone(salt_and_pepper_bitmap);
	maximum_bitmap = f.maximumFilter(maximum_bitmap, color);

	char output[30] = "grey_";
	strcat(output, s);
	std::cout << output << std::endl;
	//Image.WriteToFile(output);
	if (FreeImage_Save(FIF_BMP, gray_bitmap, output, 0)){
		cout << "Succesfully saved!!!!!!" << endl;
	}
	if (FreeImage_Save(FIF_BMP, red_bitmap, "redChannel.bmp", 0)){
		cout << "Succesfully saved!!!!!!" << endl;
	}
	if (FreeImage_Save(FIF_BMP, green_bitmap, "greenChannel.bmp", 0)){
		cout << "Succesfully saved!!!!!!" << endl;
	}
	if (FreeImage_Save(FIF_BMP, blue_bitmap, "blueChannel.bmp", 0)){
		cout << "Succesfully saved!!!!!!" << endl;
	}
	if (FreeImage_Save(FIF_BMP, salt_and_pepper_bitmap, "SaltAndPepper.bmp", 0)){
		cout << "SALT AND PEPPA" << endl;
	}
	if (FreeImage_Save(FIF_BMP, median_bitmap, "median.bmp", 0)){
		cout << "MEDIAANA" << endl;
	}
	if (FreeImage_Save(FIF_BMP, minimum_bitmap, "minimum.bmp", 0)){
		cout << "MINIIIIIIIIII" << endl;
	}
	if (FreeImage_Save(FIF_BMP, maximum_bitmap, "maximum.bmp", 0)){
		cout << "MAXIIIIIIIIII" << endl;
	}

	h.createHistogram256(gray_bitmap);
	h.createHistogram10(gray_bitmap);

	h.createHistogram10Red(red_bitmap);
	h.createHistogram10Green(green_bitmap);
	h.createHistogram10Blue(blue_bitmap);

	std::cin.get();
	return 0;
}

