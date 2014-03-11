#include "Threshold.h"

//AUTHOR Bryan Baan, Chanan van Ooijen, Yusuf Syakur
Threshold::Threshold(){
	bt = new BaseTimer();
}


Threshold::~Threshold(){
	delete bt;
}

//This method is used to create a thresholded image. It determines a threshold PER pixel and then sets it to 1 (255 - white) or to 0 (0 - black).
void Threshold::CreateThresholdImage(Image &sourceImage, Image &destinationImage) {
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

	//Threshold determination
	int imageSize = srcHeight * srcWidth;
	int temp = 0;
	int* window;
	int index = 0;
	window = (int *)malloc(sizeof(int)* 121);
	for (int u = 0; u < 121; u++) {
		window[u] = 0;
	}
	
	//The threshold for every pixel will be retrieved by using an 11x11 Mean filter.
	//That is also what these for loops are for.
	for (int x = 5; x < srcWidth - 5; x++)
	{
		for (int y = 5; y < srcHeight - 5; y++)
		{
			for (int newX = (x-5); newX < (x + 5); newX++)
			{
				for (int newY = (y-5); newY < (y + 5); newY++)
				{
					window[index] = sourceImage.GetPixelRed(newX, newY);
					index++;
				}
			}
			//Accumulating all the values of the mean filter (11x11)
			for (int i = 0; i < 121; i++) {
				temp += window[i];
			}
			//determinating the threshold
			temp = temp / 121;

			int threshold = temp;
			
			//applying the threshold to the current pixel.
			if (sourceImage.GetPixelRed(x, y) > threshold) {
				destinationImage.SetPixel(x, y, 0 << redPixelShift | 0 << greenPixelShift | 0 << bluePixelShift);
			}
			else {
				destinationImage.SetPixel(x, y, 255 << redPixelShift | 255 << greenPixelShift | 255 << bluePixelShift);
			}
			temp = 0;
			index = 0;
		}
	}

	

	bt->stop();
	std::cout << "Time for the Threshold function: " << bt->elapsedMicroSeconds() << " Microseconds (" << bt->elapsedMilliSeconds() << "ms)" << std::endl;
}



