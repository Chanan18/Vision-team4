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
	void MoveImage(Image &sourceImage, Image &destinationImage, int width, int height);
	void TurnImage(Image &sourceImage, Image &destinationImage, int angle);
};

#endif

