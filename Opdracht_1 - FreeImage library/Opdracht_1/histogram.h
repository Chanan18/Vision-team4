/* ========================================================================== */
/*                                                                            */
/*   histogram.h                                                              */
/*   (c) 2013 Chanan van Ooijen & Bryan Baan                                  */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */

#include "stdafx.h"
#include <fstream>
#include "FreeImage.h"
using namespace std;

class histogram{
private:
	//! Declares the Height of the image
	int HEIGHT;

	//! Declares the Width of the image
	int WIDTH;

public:

	//! This method has parameter bitmap and creates a histogram with binnumber 256 
	void createHistogram256(FIBITMAP* gray_bitmap);

	//! This method has parameter bitmap  and creates a histogram with binnumber 10 
	void createHistogram10(FIBITMAP* gray_bitmap);

	//! This method has parameter bitmap  and creates a histogram with binnumber 10 
	void createHistogram10Red(FIBITMAP* gray_bitmap);

	//! This method has parameter bitmap  and creates a histogram with binnumber 10 
	void createHistogram10Green(FIBITMAP* gray_bitmap);

	//! This method has parameter bitmap  and creates a histogram with binnumber 10 
	void createHistogram10Blue(FIBITMAP* gray_bitmap);


};