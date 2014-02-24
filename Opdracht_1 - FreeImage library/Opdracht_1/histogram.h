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
public:

	//! This method has parameter bitmap (type: FIBITMAP) and creates a histogram with binnumber 256 
	void createHistogram256(FIBITMAP* gray_bitmap, string s);

	//! This method has parameter bitmap (type: FIBITMAP) and creates a histogram with binnumber 10 
	void createHistogram10(FIBITMAP* gray_bitmap);

	//! This method has parameter bitmap (type: FIBITMAP) and creates a histogram with binnumber 10 (based on red channel) 
	void createHistogram10Red(FIBITMAP* gray_bitmap);

	//! This method has parameter bitmap (type: FIBITMAP) and creates a histogram with binnumber 10 (based on green channel)
	void createHistogram10Green(FIBITMAP* gray_bitmap);

	//! This method has parameter bitmap (type: FIBITMAP) and creates a histogram with binnumber 10 (based on blue channel)
	void createHistogram10Blue(FIBITMAP* gray_bitmap);


};