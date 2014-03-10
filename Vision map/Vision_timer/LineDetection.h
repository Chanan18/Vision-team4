#ifndef LineDetection_H
#define LineDetection_H
#include "Image.h"
#include "exectimer.h"
#include <iostream>

//AUTHOR Lars Veenendaal

class LineDetection {
private:
	BaseTimer* bt;
public:
	LineDetection();
	~LineDetection();
	void CreateLineDetectionImage(Image &sourceImage, Image &destinationImage);
	void DetermineCornerPoints(Image &sourceImage, int(&result_array)[4][2]);
};

#endif