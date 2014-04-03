#include "Translations.h"
#include <math.h>
#define PI 3.14159265

// AUTHOR Yusuf Syakur
Translations::Translations(){
	bt = new BaseTimer();
}


Translations::~Translations(){
	delete bt;
}

//This method defines edges by applying a x and y mask. The magnitude of both directions x and y will be combined resulting a value that represents an edge.
void Translations::MoveImage(Image &sourceImage, Image &destinationImage, int width, int height) {
	bt->reset();
	bt->start();

	int srcHeight = sourceImage.GetHeight();
	int srcWidth = sourceImage.GetWidth();

	int dstHeight = destinationImage.GetHeight();
	int dstWidth = destinationImage.GetWidth();

	if (srcWidth != dstWidth && srcHeight != dstHeight) {
		std::cout << "Error images are not the same size" << std::endl;
		return;
	}

	//The masks
	double kernel[3][3] = { { 1, 0, width	},
							{ 0, 1, height	},
							{ 0, 0, 1		} };
	double newX;
	double newY;

	for (int i = 0; i < dstWidth; i++) {
		for (int j = 0; j < dstHeight; j++) {
			destinationImage.SetPixel(i, j, 0 << redPixelShift | 0 << greenPixelShift | 0 << bluePixelShift);
		}
	}

	//For each pixel, apply the masks and combine them.
	for (int x = 1; x < dstWidth - 1; ++x){
		for (int y = 1; y < dstHeight - 1; ++y){
			newX = kernel[0][0] * x + kernel[0][1] * y + kernel[0][2];
			newY = kernel[1][0] * x + kernel[1][1] * y + kernel[1][2];
			if (newX < sourceImage.GetWidth() && newY < sourceImage.GetHeight()){
				destinationImage.SetPixel(newX, newY, sourceImage.GetPixelRed(x, y) << redPixelShift | sourceImage.GetPixelGreen(x, y) << greenPixelShift | sourceImage.GetPixelBlue(x, y) << bluePixelShift);
			}
		}
	}

	bt->stop();
	std::cout << "Time for the Sobel edge detection function: " << bt->elapsedMicroSeconds() << " Microseconds (" << bt->elapsedMilliSeconds() << "ms)" << std::endl;
}

void Translations::TurnImage(Image &sourceImage, Image &destinationImage, int angle) {
	bt->reset();
	bt->start();

	int srcHeight = sourceImage.GetHeight();
	int srcWidth = sourceImage.GetWidth();

	int dstHeight = destinationImage.GetHeight();
	int dstWidth = destinationImage.GetWidth();

	if (srcWidth != dstWidth && srcHeight != dstHeight) {
		std::cout << "Error images are not the same size" << std::endl;
		return;
	}
	
	//The masks
	double kernel[3][3] = { { cos(angle*PI / 180), -sin(angle*PI / 180), 0 },
							{ sin(angle*PI / 180), cos(angle*PI / 180), 0 },
							{ 0,			0			, 1	} };
	double newX;
	double newY;
	std::cout << cos(30) << std::endl;
	std::cout << sin(30) << std::endl;
	for (int i = 0; i < dstWidth; i++) {
		for (int j = 0; j < dstHeight; j++) {
			destinationImage.SetPixel(i, j, 0 << redPixelShift | 0 << greenPixelShift | 0 << bluePixelShift);
		}
	}

	//For each pixel, apply the masks and combine them.
	for (int x = 0; x < dstWidth; ++x){
		for (int y = 0; y < dstHeight; ++y){
			newX = kernel[0][0] * x + kernel[0][1] * y + kernel[0][2];
			newY = kernel[1][0] * x + kernel[1][1] * y + kernel[1][2];
			if (newX < sourceImage.GetWidth() && newY < sourceImage.GetHeight()){
				if (newX > 0 && newY > 0)
				destinationImage.SetPixel(newX, newY, sourceImage.GetPixelRed(x, y) << redPixelShift | sourceImage.GetPixelGreen(x, y) << greenPixelShift | sourceImage.GetPixelBlue(x, y) << bluePixelShift);
			}
		}
	}

	bt->stop();
	std::cout << "Time for the Sobel edge detection function: " << bt->elapsedMicroSeconds() << " Microseconds (" << bt->elapsedMilliSeconds() << "ms)" << std::endl;
}

