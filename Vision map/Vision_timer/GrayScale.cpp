#include "GrayScale.h"
//#define redPixel 24
//#define greenPixel 16
//#define bluePixel 8
//#define alphaPixel 0

// Default constructor
GrayScale::GrayScale() {
	bt = new BaseTimer();
}

// Destructor
GrayScale::~GrayScale() {
	delete bt;
}

// This method creates an image with grayvalues (removes color from images)
void GrayScale::CreateGrayScaleImage(Image &sourceImage, Image &destinationImage) {
	bt->reset();
	bt->start();

	int grayValue;

	// Check if sourceImage and destinationImage are the samen size, if not return immediately
	if(sourceImage.GetWidth() != destinationImage.GetWidth() && sourceImage.GetHeight() != destinationImage.GetHeight()) {
		std::cout << "Error images are not the same size" << std::endl;
		return;
	}

	// Calcute for every single pixel the gray vlue and set the pixels in destinationImage
	for(int y = sourceImage.GetHeight() - 1; y >= 0; y--) {
		for(int x = sourceImage.GetWidth() - 1; x >= 0; x--) {
			grayValue = (int)((sourceImage.GetPixelRed(x, y) * 0.30) + (sourceImage.GetPixelGreen(x, y) * 0.59) + (sourceImage.GetPixelBlue(x, y) * 0.11));
			destinationImage.SetPixel(x, y, (grayValue << redPixelShift) | (grayValue << greenPixelShift) | (grayValue << bluePixelShift));
		}
	}

	bt->stop();
	std::cout << "Time for the Grayscale function: " << bt->elapsedMicroSeconds() << " Microseconds (" << bt->elapsedMilliSeconds() << "ms)" << std::endl;
}
