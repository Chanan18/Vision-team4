#ifndef Histogram_H
#define Histogram_H
#include "Image.h"
#include "exectimer.h"
#include <iostream>
#include <fstream>

class Histogram{
private:
	// Define BaseTimer object
	BaseTimer* bt;

	// Define output location where histograms have to be saved
	std::string outputLocation = "../Histogrammen/";
public:
	// Default constructor
	Histogram();

	// Destructor
	~Histogram();

	// Creates 3 histograms (1 for every color channel) with an binnumber (which is variable)
	void CreateNormalizedHistogramCOLOR(Image &sourceImage, int binnr);

	// Create a histogram (based on gray values) with an binnumber (which is variable)
	void CreateNormalizedHistogramGRAY(Image &sourceImage, int binnr);
};

#endif