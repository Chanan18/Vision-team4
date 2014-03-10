#ifndef Histogram_H
#define Histogram_H
#include "Image.h"
#include "exectimer.h"
#include <iostream>
#include <fstream>

class Histogram{
private:
	BaseTimer* bt;
public:
	Histogram();
	~Histogram();
	void CreateHistogramY(Image &sourceImage);
	void CreateHistogramX(Image &sourceImage);
	void CreateNormalizedHistogramCOLOR(Image &sourceImage, int binnr);
	void CreateNormalizedHistogramGRAY(Image &sourceImage, int binnr);
};

#endif