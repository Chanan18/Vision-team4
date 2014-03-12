#include "Equalize.h"
//#define redPixel 24
//#define greenPixel 16
//#define bluePixel 8
//#define alphaPixel 0

using namespace std;

// Default constructor
Equalize::Equalize() {
	bt = new BaseTimer();
}

// Destructor
Equalize::~Equalize() {
	delete bt;
}

// This method creates an image with equalized grayvalues. (removes foggyness on pictures)
void Equalize::CreateEqualizedImage(Image &sourceImage, Image &destinationImage) {
	bt->reset();
	bt->start();

	int height = sourceImage.GetHeight();
	int width = sourceImage.GetWidth();
	int totalPixels = height * width;
	int pixelValue = 0;

	float alpha = 255 / float(totalPixels);
	float equalized_histogram_array[256];
	float histogram_array[256];

	// The following for lus we set all values to 0 in the array
	for (int i = 0; i < 256; i++){
		histogram_array[i] = 0;
	}

	// The next 2 for lusses we will get all the red pixel values (which will be an value from 0 to 255) and increment the value in the array on element red pixel value
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			pixelValue = sourceImage.GetPixelRed(i, j);
			histogram_array[pixelValue] ++;
		}
	}

	equalized_histogram_array[0] = histogram_array[0] * alpha;

	// Creates an equalized array from normal histogram
	for (int i = 1; i < 256; i++){
		equalized_histogram_array[i] = equalized_histogram_array[i - 1] + (histogram_array[i] * alpha);
	}

	

	
	// Creating an equalized imaged from equalialized_histogram_array
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			pixelValue = sourceImage.GetPixelRed(i, j);
			destinationImage.SetPixel(i, j, ((int)equalized_histogram_array[pixelValue] << redPixelShift) | ((int)equalized_histogram_array[pixelValue] << greenPixelShift) | ((int)equalized_histogram_array[pixelValue] << bluePixelShift));
		}
	}

	bt->stop();
	std::cout << "Time for the Equalize function: " << bt->elapsedMicroSeconds() << " Microseconds (" << bt->elapsedMilliSeconds() << "ms)" << std::endl;
}
