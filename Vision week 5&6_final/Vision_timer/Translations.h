#ifndef Translations_H
#define Translations_H
#include "Image.h"
#include "exectimer.h"
#include <iostream>

class Translations {
private:
	BaseTimer* bt;
public:
	Translations();
	~Translations();
	double** createBackwardsKernel(bool rotation);
	void MatrixImage(Image &sourceImage, Image &destinationImage, int n, double** backwards_kernel, int interpolation);
};

#endif

