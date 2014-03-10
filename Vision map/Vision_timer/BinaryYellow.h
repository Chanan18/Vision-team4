#include "Image.h"
#include "exectimer.h"
#include <iostream>

class BinaryYellow {
private:
	BaseTimer* bt;
public:
	BinaryYellow();
	~BinaryYellow();
	void CreateBinaryImage(Image &sourceImage, Image &destinationImage);
};
