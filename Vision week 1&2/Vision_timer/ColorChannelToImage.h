/* ========================================================================== */
/*                                                                            */
/*   ColorChannelToImage.h                                                    */
/*   (c) 2013 Chanan van Ooijen & Bryan Baan                                  */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */
#ifndef ColorChannelToImage_H
#define ColorChannelToImage_H
#include "Image.h"
#include "exectimer.h"
#include <iostream>

class ColorChannelToImage {
private:
	// Define BaseTimer object
	BaseTimer* bt;
public:
	// Default constructor
	ColorChannelToImage();
	// Destructor

	~ColorChannelToImage();

	// This method has parameters an source image, an destination image
	//
	// This method will create an image (only red channel open) from sourceImage and store it in destionationImage
	void CreateRedChannelImage(Image &sourceImage, Image &destinationImage);

	// This method has parameters an source image, an destination image
	//
	// This method will create an image (only green channel open) from sourceImage and store it in destionationImage
	void CreateGreenChannelImage(Image &sourceImage, Image &destinationImage);

	// This method has parameters an source image, an destination image
	//
	// This method will create an image (only blue channel open) from sourceImage and store it in destionationImage
	void CreateBlueChannelImage(Image &sourceImage, Image &destinationImage);
};

#endif