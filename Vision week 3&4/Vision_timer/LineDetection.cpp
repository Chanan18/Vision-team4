#include "LineDetection.h"
#include <fstream>

//AUTHOR Bryan Baan & Chanan van Ooijen
//AUTHOR Lars Veenendaal
using namespace std;
LineDetection::LineDetection() {
	bt = new BaseTimer();
}


LineDetection::~LineDetection() {
	delete bt;
}

//This method is used to determine the position of the license plate in the image by extracting
//the histogram values and detecting the edges in the histogram.
void LineDetection::CreateLineDetectionImage(Image &sourceImage, Image &destinationimage) {

	//Some variables that will be used.
	int imageHeight = sourceImage.GetHeight();
	int imageWidth = sourceImage.GetWidth();
	int totalPixels = imageWidth * imageHeight;
	int before = 0;
	int after = 0;
	int up = 0;
	int down = 0;
	int* XValues;
	int* YValues;
	string valuesX;
	string valuesY;

	//initialisation of "variable" int array
	XValues = (int *)malloc(sizeof(int)* imageWidth);
	YValues = (int *)malloc(sizeof(int)* imageHeight);

	//ifstreams to read the histograms
	ifstream histogramX;
	ifstream histogramY;
	histogramX.open("histogramX.csv", ios::in);
	histogramY.open("histogramY.csv", ios::in);

	//for loops to determine the values of the histogram and convert them to int array.
	//The stoi(std::string) method simply parses the string to an int.
	for (int i = 0; i < imageWidth; i++) {
		getline(histogramX, valuesX, '\n');
		XValues[i] = stoi(valuesX);
	}
	for (int i = 0; i < imageHeight; i++) {
		getline(histogramY, valuesY, '\n');
		YValues[i] = stoi(valuesY);
	}

	int highestAmountOfEdges = XValues[0];
	int highestEdgesX = 0;

	//Determine the highest edge within the histogram and save its position
	for (int i = 1; i < imageWidth; i++){
		if (XValues[i] >= highestAmountOfEdges){
			highestAmountOfEdges = XValues[i];
			highestEdgesX = i;
		}
	}

	//With this while loop we will walk back toward the spot where the edge will become 2 or lower.
	//This indicated that we have found the end of our edge and  thus, the end of our license plate.
	while (XValues[highestEdgesX] >= 2){
		highestEdgesX--;
	}
	//This +1 means that we will walk UP this time to detect the other edge end.
	int highestEdges2X = highestEdgesX + 1;
	while (XValues[highestEdges2X] >= 2) {
		highestEdges2X++;
	}

	//These for lusses are blackening the entire picture except the X's that have an edge (close to the license plate)
	//that way you will have black on the left and right side of the license plate. These lusses create one vertical stroke that
	//still can be seen.
	for (int i = 0; i < highestEdgesX; i++) {
		for (int j = 0; j < sourceImage.GetHeight(); j++) {
			destinationimage.SetPixel(i, j, (0 << redPixelShift) | (0 << greenPixelShift) | (0 << bluePixelShift));
		}
	}
	for (int i = highestEdges2X; i < sourceImage.GetWidth(); i++) {
		for (int j = 0; j < sourceImage.GetHeight(); j++) {
			destinationimage.SetPixel(i, j, (0 << redPixelShift) | (0 << greenPixelShift) | (0 << bluePixelShift));
		}
	}

	//Same steps as for X, but for the Y coordinates this time.
	highestAmountOfEdges = YValues[0];
	int highestEdgesY = 0;

	for (int i = 1; i < imageHeight; i++){
		if (YValues[i] >= highestAmountOfEdges){
			highestAmountOfEdges = YValues[i];
			highestEdgesY = i;
		}
	}

	while (YValues[highestEdgesY] >= 2){
		highestEdgesY--;
	}
	int highestEdges2Y = highestEdgesY + 1;
	while (YValues[highestEdges2Y] >= 2) {
		highestEdges2Y++;
	}

	//This does exactly the same as the X for lusses, but it creates horizontal strokes instead of vertical ones.
	for (int i = 0; i < highestEdgesY; i++) {
		for (int j = 0; j < sourceImage.GetWidth(); j++) {
			destinationimage.SetPixel(j, i, (0 << redPixelShift) | (0 << greenPixelShift) | (0 << bluePixelShift));
		}
	}
	for (int i = highestEdges2Y; i < sourceImage.GetHeight(); i++) {
		for (int j = 0; j < sourceImage.GetWidth(); j++) {
			destinationimage.SetPixel(j, i, (0 << redPixelShift) | (0 << greenPixelShift) | (0 << bluePixelShift));
		}
	}
}

//This method will remove any surplus noise or random white spots in the picture and create histograms of that (and an image ofcourse).
//Also, the final license plate coordinates will be created here, ready for comparison.
//The code in this method is very similar to the code of the method above, but certainly needed.
//If you need explanation of this code, please check the comments written in the method above.
void LineDetection::DetermineCornerPoints(Image &sourceImage, int(&result_array)[4][2]) {
	int imageHeight = sourceImage.GetHeight();
	int imageWidth = sourceImage.GetWidth();
	int totalPixels = imageWidth * imageHeight;
	int topLeftPixel = 0;
	int topRightPixel = 0;
	int bottomLeftPixel = 0;
	int bottomRightPixel = 0;
	int* XValues;
	int* YValues;
	string valuesX;
	string valuesY;

	XValues = (int *)malloc(sizeof(int)* imageWidth);
	YValues = (int *)malloc(sizeof(int)* imageHeight);

	ifstream histogramX;
	ifstream histogramY;
	histogramX.open("histogramX.csv", ios::in);
	histogramY.open("histogramY.csv", ios::in);

	for (int i = 0; i < imageWidth; i++) {
		getline(histogramX, valuesX, '\n');
		XValues[i] = stoi(valuesX);
	}
	for (int i = 0; i < imageHeight; i++) {
		getline(histogramY, valuesY, '\n');
		YValues[i] = stoi(valuesY);
	}

	int highestAmountOfEdges = XValues[0];
	int highestEdgesX = 0;

	for (int i = 1; i < imageWidth; i++){
		if (XValues[i] >= highestAmountOfEdges){
			highestAmountOfEdges = XValues[i];
			highestEdgesX = i;
		}
	}

	while (XValues[highestEdgesX] != 0){
		highestEdgesX--;
	}
	int highestEdges2X = highestEdgesX + 1;
	while (XValues[highestEdges2X] != 0) {
		highestEdges2X++;
	}

	highestAmountOfEdges = YValues[0];
	int highestEdgesY = 0;

	for (int i = 1; i < imageHeight; i++){
		if (YValues[i] >= highestAmountOfEdges){
			highestAmountOfEdges = YValues[i];
			highestEdgesY = i;
		}
	}

	while (YValues[highestEdgesY] != 0){
		highestEdgesY--;
	}
	int highestEdges2Y = highestEdgesY + 1;
	while (YValues[highestEdges2Y] != 0) {
		highestEdges2Y++;
	}

	//This is a check to determine if we actually got the right coordinates.
	cout << "Top left corner: " << "(" << highestEdgesX << "," << highestEdgesY << ")" << endl;
	cout << "Top right corner: " << "(" << highestEdges2X << "," << highestEdgesY << ")" << endl;
	cout << "bottom left corner: " << "(" << highestEdgesX << "," << highestEdges2Y << ")" << endl;
	cout << "bottom right corner: " << "(" << highestEdges2X << "," << highestEdges2Y << ")" << endl;

	//These are the corner coordinates that we found.
	//topLeftPixel = sourceImage.GetPixel(highestEdgesX, highestEdgesY);
	//topRightPixel = sourceImage.GetPixel(highestEdges2X, highestEdgesY);
	//bottomLeftPixel = sourceImage.GetPixel(highestEdgesX, highestEdges2Y);
	//bottomRightPixel = sourceImage.GetPixel(highestEdges2X, highestEdges2Y);

	//Info voor lars:
	//Hieronder moet er een vergelijking worden gemaakt met de waarden die wij gevonden hebben.
	//De pixels die wij hebben gevonden worden hierboven opgeslagen (namen zijn denk ik vrij duidelijk).
	//Succes met de vergelijking maken. Als dat niet lukt, is het beter als je dat gewoon verwijderd en daarna pas inleverd.
	result_array[0][0] = highestEdgesX;
	result_array[0][1] = highestEdgesY;
	result_array[1][0] = highestEdges2X;
	result_array[1][1] = highestEdgesY;

	result_array[2][0] = highestEdgesX;
	result_array[2][1] = highestEdges2Y;
	result_array[3][0] = highestEdges2X;
	result_array[3][1] = highestEdges2Y;

	//result_array[4][2] = { { highestEdgesX, highestEdgesY }, { highestEdges2X, highestEdgesY }, { highestEdgesX, highestEdges2Y }, { highestEdges2X, highestEdges2Y } };
}



	