#ifndef SobelFilter_H
#define SobelFilter_H
#include "Image.h"
#include "exectimer.h"
#include <iostream>

class SobelFilter {
private:
	BaseTimer* bt;
public:
	SobelFilter();
	~SobelFilter();
	void CreateSobelImage(Image &sourceImage, Image &destinationImage);
};

#endif

