#ifndef Filter_H
#define Filter_H
#include "Image.h"
#include "exectimer.h"
#include <iostream>

class Filter {
private:
	// Define BaseTimer object
	BaseTimer* bt;
public:
	// Default constructor
	Filter();

	// Destructor
	~Filter();

	// This method has parameters a source image, a destination image and an int which represent the size of the median filter
	//
	// This method will apply the median filter on sourceImage and save it on destinationImage
	void CreateMedianFilterImage(Image &sourceImage, Image &destinationImage, int size);

	// This method has parameters a source image, a destination image and an int which represent the size of the minimum filter
	//
	// This method will apply the minimum filter on sourceImage and save it on destinationImage
	void CreateMinimumFilterImage(Image &sourceImage, Image &destinationImage, int size);

	// This method has parameters a source image, a destination image and an int which represent the size of the maximum filter
	//
	// This method will apply the maximum filter on sourceImage and save it on destinationImage
	void CreateMaximumFilterImage(Image &sourceImage, Image &destinationImage, int size);
};

#endif