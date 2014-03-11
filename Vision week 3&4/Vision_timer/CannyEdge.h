#include "Image.h"
#include "exectimer.h"
#include <iostream>

class CannyEdge {
private:
	BaseTimer* bt;
public:
	CannyEdge();
	~CannyEdge();
	void CreateCannyEdge(Image &sourceImage, Image &destinationImage);
};
