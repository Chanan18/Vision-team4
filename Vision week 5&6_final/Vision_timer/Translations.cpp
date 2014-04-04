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

struct corner {
	double x;
	double y;
};

double** Translations::createBackwardsKernel(bool rotation){

	double** kernel = new double*[3];
	
	for (int i = 0; i < 3; i++){
		kernel[i] = new double[3];
	}

	std::ifstream in("Matrix.txt");

	if (!in){
		std::cout << "Cannot open file.\n";
		//return;
	}


	for (int x = 0; x < 3; x++){
		for (int y = 0; y < 3; y++){
			in >> kernel[x][y];
		}
	}

	if (rotation) {
		kernel[0][0] = cos(kernel[0][0] * PI / 180.0);
		kernel[0][1] = -sin(kernel[0][1] * PI / 180.0);
		kernel[1][0] = sin(kernel[1][0] * PI / 180.0);
		kernel[1][1] = cos(kernel[1][1] * PI / 180.0);
	}

	double determinant0_0 = (kernel[1][1] * kernel[2][2]) - (kernel[2][1] * kernel[1][2]);
	double determinant0_1 = (kernel[0][0] * kernel[2][2]) - (kernel[2][0] * kernel[1][2]);
	double determinant0_2 = (kernel[1][0] * kernel[2][1]) - (kernel[2][0] * kernel[1][1]);

	double determinant = (kernel[0][0] * determinant0_0) - (kernel[0][1] * determinant0_1) + (kernel[0][2] * determinant0_2);

	std::cout << "\nDeterminant is: " << determinant << "\n";

	double** backwords_kernel = new double*[3];

	for (int i = 0; i < 3; i++){
		backwords_kernel[i] = new double[3];
	}

	backwords_kernel[0][0] = kernel[0][0];
	backwords_kernel[0][1] = kernel[1][0];
	backwords_kernel[0][2] = kernel[2][0];
	backwords_kernel[1][0] = kernel[0][1];
	backwords_kernel[1][1] = kernel[1][1];
	backwords_kernel[1][2] = kernel[2][1];
	backwords_kernel[2][0] = kernel[0][2];
	backwords_kernel[2][1] = kernel[1][2];
	backwords_kernel[2][2] = kernel[2][2];

	double backwords01 = (backwords_kernel[1][1] * backwords_kernel[2][2]) - (backwords_kernel[2][1] * backwords_kernel[1][2]);
	double backwords02 = (backwords_kernel[1][0] * backwords_kernel[2][2]) - (backwords_kernel[2][0] * backwords_kernel[1][2]);
	double backwords03 = (backwords_kernel[1][0] * backwords_kernel[2][1]) - (backwords_kernel[2][0] * backwords_kernel[1][1]);
	double backwords11 = (backwords_kernel[0][1] * backwords_kernel[2][2]) - (backwords_kernel[2][1] * backwords_kernel[0][2]);
	double backwords12 = (backwords_kernel[0][0] * backwords_kernel[2][2]) - (backwords_kernel[2][0] * backwords_kernel[0][2]);
	double backwords13 = (backwords_kernel[0][0] * backwords_kernel[2][1]) - (backwords_kernel[2][0] * backwords_kernel[0][1]);
	double backwords21 = (backwords_kernel[0][1] * backwords_kernel[1][2]) - (backwords_kernel[2][1] * backwords_kernel[0][2]);
	double backwords22 = (backwords_kernel[0][0] * backwords_kernel[1][2]) - (backwords_kernel[1][0] * backwords_kernel[0][2]);
	double backwords23 = (backwords_kernel[0][0] * backwords_kernel[1][1]) - (backwords_kernel[1][0] * backwords_kernel[0][1]);

	backwords_kernel[0][0] = (backwords01 * 1);
	backwords_kernel[0][1] = (backwords02 * -1);
	backwords_kernel[0][2] = (backwords03 * 1);
	backwords_kernel[1][0] = (backwords11 * -1);
	backwords_kernel[1][1] = (backwords12 * 1);
	backwords_kernel[1][2] = (backwords13 * -1);
	backwords_kernel[2][0] = (backwords21 * 1);
	backwords_kernel[2][1] = (backwords22 * -1);
	backwords_kernel[2][2] = (backwords23 * 1);

	double value = 1 / determinant;

	for (int x = 0; x < 3; x++){
		for (int y = 0; y < 3; y++){
			backwords_kernel[x][y] = backwords_kernel[x][y] * value;
		}
	}

	return backwords_kernel;
}


void Translations::MatrixImage(Image &sourceImage, Image &destinationImage, int n, double** backwards_kernel, int interpolation) {
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
	

	double newX;
	double newY;

	for (int i = 0; i < dstWidth; i++) {
		for (int j = 0; j < dstHeight; j++) {
			destinationImage.SetPixel(i, j, 0 << redPixelShift | 0 << greenPixelShift | 0 << bluePixelShift);
		}
	}
	
	switch (interpolation){
		case 0:
			//For each pixel, apply the masks and combine them.
			for (int x = 0; x < dstWidth; ++x){
				for (int y = 0; y < dstHeight; ++y){
					newX = std::round(backwards_kernel[0][0] * x + backwards_kernel[0][1] * y + backwards_kernel[0][2]);
					newY = std::round(backwards_kernel[1][0] * x + backwards_kernel[1][1] * y + backwards_kernel[1][2]);
					if (newX < sourceImage.GetWidth() && newY < sourceImage.GetHeight()){
						if (newX >= 0 && newY >= 0)
							destinationImage.SetPixel(x, y, sourceImage.GetPixelRed(newX, newY) << redPixelShift | sourceImage.GetPixelGreen(newX, newY) << greenPixelShift | sourceImage.GetPixelBlue(newX, newY) << bluePixelShift);
					}
				}
			}
			break;
		case 1:
			for (int x = 0; x < dstWidth-1; ++x){
				for (int y = 0; y < dstHeight-1; ++y){
					double newX = backwards_kernel[0][0] * x + backwards_kernel[0][1] * y + backwards_kernel[0][2];
					double newY = backwards_kernel[1][0] * x + backwards_kernel[1][1] * y + backwards_kernel[1][2];

					if (newX <= sourceImage.GetWidth() && newY <= sourceImage.GetHeight() && newX >= 0 && newY >= 0){
						//create cornerpoint structs
						corner topleft;
						corner topright;
						corner bottomleft;
						corner bottomright;

						//fill structs with coordinates
						topleft.x = (int)newX; topleft.y = (int)newY;
						topright.x = (int)(newX + 1); topright.y = (int)newY;
						bottomleft.x = (int)newX; bottomleft.y = (int)(newY + 1);
						bottomright.x = (int)(newX + 1); bottomright.y = (int)(newY + 1);

						double topleftSurface = (newX - topleft.x) * (newY - topleft.y);//deltaX * deltaY.
						double toprightSurface = (topright.x - newX) * (newY - topright.y);//deltaX * deltaY.
						double bottomleftSurface = (newX - bottomleft.x) * (bottomleft.y - newY);//deltaX * deltaY.
						double bottomrightSurface = (bottomright.x - newX) * (bottomright.y - newY);//deltaX * deltaY.
						double totalSurface = topleftSurface + toprightSurface + bottomleftSurface + bottomrightSurface;

						//Nu moet de surface waarde gewogen worden.
						double percent1 = (topleftSurface / totalSurface) * 100;
						double percent2 = (toprightSurface / totalSurface) * 100;
						double percent3 = (bottomleftSurface / totalSurface) * 100;
						double percent4 = (bottomrightSurface / totalSurface) * 100;
						
						//weight of colorpixels will be calculated using the percent that we just calculated.
						int leftUpperPixelRed = sourceImage.GetPixelRed(topleft.x,topleft.y);
						int leftUpperPixelGreen = sourceImage.GetPixelGreen(topleft.x, topleft.y);
						int leftUpperPixelBlue = sourceImage.GetPixelBlue(topleft.x, topleft.y);

						int rightUpperPixelRed = sourceImage.GetPixelRed(topright.x, topright.y);
						int rightUpperPixelGreen = sourceImage.GetPixelGreen(topright.x, topright.y);
						int rightUpperPixelBlue = sourceImage.GetPixelBlue(topright.x, topright.y);

						int leftBottomPixelRed = sourceImage.GetPixelRed(bottomleft.x, bottomleft.y);
						int leftBottomPixelGreen = sourceImage.GetPixelGreen(bottomleft.x, bottomleft.y);
						int leftBottomPixelBlue = sourceImage.GetPixelBlue(bottomleft.x, bottomleft.y);

						int rightBottomPixelRed = sourceImage.GetPixelRed(bottomright.x, bottomright.y);
						int rightBottomPixelGreen = sourceImage.GetPixelGreen(bottomright.x, bottomright.y);
						int rightBottomPixelBlue = sourceImage.GetPixelBlue(bottomright.x, bottomright.y);

						int newRedPixelValue = ((leftUpperPixelRed * percent1) + (rightUpperPixelRed * percent2) + (leftBottomPixelRed * percent3) + (rightBottomPixelRed * percent4)) / 100;
						int newGreenPixelValue = ((leftUpperPixelGreen * percent1) + (rightUpperPixelGreen * percent2) + (leftBottomPixelGreen * percent3) + (rightBottomPixelGreen * percent4)) / 100;
						int newBluePixelValue = ((leftUpperPixelGreen * percent1) + (rightUpperPixelBlue * percent2) + (leftBottomPixelBlue * percent3) + (rightBottomPixelBlue * percent4)) / 100;

						destinationImage.SetPixel(x, y, newRedPixelValue << redPixelShift | newGreenPixelValue << greenPixelShift | newBluePixelValue << bluePixelShift);

					}
					
					double topleftSurface = 0;
					double toprightSurface = 0;
					double bottomleftSurface = 0;
					double bottomrightSurface = 0;

				}
			}
			break;
	}

	bt->stop();
	std::cout << "Time for the Sobel edge detection function: " << bt->elapsedMicroSeconds() << " Microseconds (" << bt->elapsedMilliSeconds() << "ms)" << std::endl;
}

