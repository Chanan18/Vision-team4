#include "CannyEdge.h"

CannyEdge::CannyEdge() {
	bt = new BaseTimer();
}


CannyEdge::~CannyEdge() {
	delete bt;
}

void CannyEdge::CreateCannyEdge(Image &sourceImage, Image &destinationImage) {
	bt->reset();
	bt->start();

	/* CANNY EDGE 
	
	This is a 2 step method.
	First we apply a gaussian filter and than we retrieve edges with the sobol.
	
	Pattern
	2	4	5	4	2
	4	9	12	9	4
	5	12	15	12	5
	4	9	12	9	4
	2	4	5	4	2

	Then divide that sum by 115.

	*/

	if (sourceImage.GetWidth() != destinationImage.GetWidth() && sourceImage.GetHeight() != destinationImage.GetHeight()) {
		std::cout << "Error images are not the same size" << std::endl;
		return;
	}
	int sumR = 0;
	int sumG = 0;
	int sumB = 0;
	for (int y = sourceImage.GetHeight() - 3; y >= 3; y--) {
		for (int x = sourceImage.GetWidth() - 3; x >= 3; x--) {
			sumR = 0;
			sumG = 0;
			sumB = 0;
			sumR = sourceImage.GetPixelRed(x - 2, y - 2) * 2;
			sumG = sourceImage.GetPixelGreen(x - 2, y - 2) * 2;
			sumB = sourceImage.GetPixelBlue(x - 2, y - 2) * 2;
			sumR += sourceImage.GetPixelRed(x - 2, y - 1) * 4;
			sumG += sourceImage.GetPixelGreen(x - 2, y - 1) * 4;
			sumB += sourceImage.GetPixelBlue(x - 2, y - 1) * 4;
			sumR += sourceImage.GetPixelRed(x - 2, y) * 5;
			sumG += sourceImage.GetPixelGreen(x - 2, y) * 5;
			sumB += sourceImage.GetPixelBlue(x - 2, y) * 5;
			sumR += sourceImage.GetPixelRed(x - 2, y + 1) * 4;
			sumG += sourceImage.GetPixelGreen(x - 2, y + 1) * 4;
			sumB += sourceImage.GetPixelBlue(x - 2, y + 1) * 4;
			sumR += sourceImage.GetPixelRed(x - 2, y + 2) * 2;
			sumG += sourceImage.GetPixelGreen(x - 2, y + 2) * 2;
			sumB += sourceImage.GetPixelBlue(x - 2, y + 2) * 2;

			sumR += sourceImage.GetPixelRed(x - 1, y - 2) * 4;
			sumG += sourceImage.GetPixelGreen(x - 1, y - 2) * 4;
			sumB += sourceImage.GetPixelBlue(x - 1, y - 2) * 4;
			sumR += sourceImage.GetPixelRed(x, y - 2) * 5;
			sumG += sourceImage.GetPixelGreen(x, y - 2) * 5;
			sumB += sourceImage.GetPixelBlue(x, y - 2) * 5;
			sumR += sourceImage.GetPixelRed(x + 1, y - 2) * 4;
			sumG += sourceImage.GetPixelGreen(x + 1, y - 2) * 4;
			sumB += sourceImage.GetPixelBlue(x + 1, y - 2) * 4;
			sumR += sourceImage.GetPixelRed(x + 2, y - 2) * 2;
			sumG += sourceImage.GetPixelGreen(x + 2, y - 2) * 2;
			sumB += sourceImage.GetPixelBlue(x + 2, y - 2) * 2;

			sumR += sourceImage.GetPixelRed(x + 2, y - 1) * 4;
			sumG += sourceImage.GetPixelGreen(x + 2, y - 1) * 4;
			sumB += sourceImage.GetPixelBlue(x + 2, y - 1) * 4;
			sumR += sourceImage.GetPixelRed(x + 2, y) * 5;
			sumG += sourceImage.GetPixelGreen(x + 2, y) * 5;
			sumB += sourceImage.GetPixelBlue(x + 2, y) * 5;
			sumR += sourceImage.GetPixelRed(x + 2, y + 1) * 4;
			sumG += sourceImage.GetPixelGreen(x + 2, y + 1) * 4;
			sumB += sourceImage.GetPixelBlue(x + 2, y + 1) * 4;
			sumR += sourceImage.GetPixelRed(x + 2, y + 2) * 2;
			sumG += sourceImage.GetPixelGreen(x + 2, y + 2) * 2;
			sumB += sourceImage.GetPixelBlue(x + 2, y + 2) * 2;

			sumR += sourceImage.GetPixelRed(x + 1, y + 2) * 4;
			sumG += sourceImage.GetPixelGreen(x - 1, y + 2) * 4;
			sumB += sourceImage.GetPixelBlue(x - 1, y - 2) * 4;
			sumR += sourceImage.GetPixelRed(x, y + 2) * 5;
			sumG += sourceImage.GetPixelGreen(x, y - 2) * 5;
			sumB += sourceImage.GetPixelBlue(x, y - 2) * 5;
			sumR += sourceImage.GetPixelRed(x + 1, y + 2) * 4;
			sumG += sourceImage.GetPixelGreen(x + 1, y + 2) * 4;
			sumB += sourceImage.GetPixelBlue(x + 1, y + 2) * 4;

			sumR += sourceImage.GetPixelRed(x + 1, y + 1) * 9;
			sumG += sourceImage.GetPixelGreen(x + 1, y + 1) * 9;
			sumB += sourceImage.GetPixelBlue(x + 1, y + 1) * 9;
			sumR += sourceImage.GetPixelRed(x - 1, y + 1) * 9;
			sumG += sourceImage.GetPixelGreen(x - 1, y + 1) * 9;
			sumB += sourceImage.GetPixelBlue(x - 1, y + 1) * 9;
			sumR += sourceImage.GetPixelRed(x + 1, y - 1) * 9;
			sumG += sourceImage.GetPixelGreen(x + 1, y - 1) * 9;
			sumB += sourceImage.GetPixelBlue(x + 1, y - 1) * 9;
			sumR += sourceImage.GetPixelRed(x - 1, y - 1) * 9;
			sumG += sourceImage.GetPixelGreen(x - 1, y - 1) * 9;
			sumB += sourceImage.GetPixelBlue(x - 1, y - 1) * 9;

			sumR += sourceImage.GetPixelRed(x + 1, y) * 12;
			sumG += sourceImage.GetPixelGreen(x + 1, y) * 12;
			sumB += sourceImage.GetPixelBlue(x + 1, y) * 12;
			sumR += sourceImage.GetPixelRed(x - 1, y) * 12;
			sumG += sourceImage.GetPixelGreen(x - 1, y) * 12;
			sumB += sourceImage.GetPixelBlue(x - 1, y) * 12;
			sumR += sourceImage.GetPixelRed(x, y + 1) * 12;
			sumG += sourceImage.GetPixelGreen(x, y + 1) * 12;
			sumB += sourceImage.GetPixelBlue(x, y + 1) * 12;
			sumR += sourceImage.GetPixelRed(x, y - 1) * 12;
			sumG += sourceImage.GetPixelGreen(x, y - 1) * 12;
			sumB += sourceImage.GetPixelBlue(x, y - 1) * 12;

			sumR += sourceImage.GetPixelRed(x, y) * 15;
			sumG += sourceImage.GetPixelGreen(x, y) * 15;
			sumB += sourceImage.GetPixelBlue(x, y) * 15;

			sumR = (sumR / 115);
			sumG = (sumR / 115);
			sumB = (sumR / 115);
			
			//printf("RESULTS: R:%d G:%d B:%d ", sumR, sumG, sumB);

			destinationImage.SetPixelRed(x, y, sumR);
			destinationImage.SetPixelGreen(x, y, sumG);
			destinationImage.SetPixelBlue(x, y, sumB);
		}
	}

	bt->stop();
	std::cout << "Time for the CannyEdge function: " << bt->elapsedMicroSeconds() << " Microseconds (" << bt->elapsedMilliSeconds() << "ms)" << std::endl;
}
