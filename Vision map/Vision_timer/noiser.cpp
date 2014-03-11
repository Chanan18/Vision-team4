#include "noiser.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>

noiser::noiser() {
	bt = new BaseTimer();
}


noiser::~noiser() {
	delete bt;
}

void noiser::saltAndPepper(Image &sourceImage, Image &destinationImage, int salt) {
	int HEIGHT = sourceImage.GetHeight();
	int WIDTH = sourceImage.GetWidth();
	srand((unsigned int)time(0));
	int i;
	int j;
	int condition = 0;
	
	int red = 0;
	int green = 0;
	int blue = 0;
	int maxValue = 255;
	int minValue = 0;

	int redValue = 0;
	int greenValue = 0;
	int blueValue = 0;

	int salt_pepper = int(salt);

	// The condition (((HEIGHT * WIDTH) / 100)*salt_pepper) defines on how many pixels we need to add salt&pepper-noise
	//
	// int i is a random number between 0 and WIDTH and int j in a random number between 0 and HEIGHT (i is our x coordinate and y our y coordinate)
	// We save the red, green and blue values in 3 different ints and check if we already changed the pixel, if not make it black or white (depends on condition % 2 if it will be made black or white)
	while (condition <= (((HEIGHT * WIDTH) / 100)*salt_pepper))  {
		i = rand() % WIDTH;
		j = rand() % HEIGHT;
		red = sourceImage.GetPixelRed(i, j);
		green = sourceImage.GetPixelGreen(i, j);
		blue = sourceImage.GetPixelBlue(i, j);
		if (!(((red == green) == blue) == minValue) || !(((red == green) == blue) == maxValue)) {
			if (condition % 2 == 0) {
				red = green = blue = 0;
			}
			else {
				red = green = blue = 255;
			}
			destinationImage.SetPixel(i, j, red << redPixelShift | green << greenPixelShift | blue << bluePixelShift);
			condition++;
		}
	}
}
