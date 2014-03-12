/* ========================================================================== */
/*                                                                            */
/*   Image.h                                                                  */
/*   (c) 2013 Kevin Bosman                                                    */
/*                                                                            */
/*   Description                                                              */
/*                                                                            */
/* ========================================================================== */
#ifndef Image_H
#define Image_H
#include <atlimage.h>
#include <string>
#include <iostream>
//Shift values
#define redPixelShift 24
#define greenPixelShift 16
#define bluePixelShift 8
#define alphaPixelShift 0

class Image {
private:
	// CImage object
	CImage* image;

	// string filename
	std::string fileName;

	// string inputLocation (location where input images are)
	std::string inputLocation = "../Images/Origineel/";

	// string outputLocation (location where output images are saved)
	std::string outputLocation = "../Images/Nieuw/";

	int height;
	int width;
	int bpp;
	unsigned int *pixel;

	// Load an image from CImage
	void LoadFromCImage();
public:
	// Empty constructor
	Image();

	// Constructor with path to image file
	Image(std::string fileName);
	
	// Copy constructor
	Image(Image &img);

	// Destructor
	~Image();

	// Load a file
	void LoadImageFromFile(std::string fileName);

	// Save an image to a file
	void SaveImageToFile(std::string prefixName);

	// Returns width of the image
	inline int GetWidth() { return width; }

	// Returns heights of the image
	inline int GetHeight() { return height;	}

	// Returns bpp of the image
	inline int GetBPP() { return bpp; }


	inline int GetPixel(int x, int y) { return pixel[x + (y * width)]; }
	
	// Returns red pixel value from coordinates x and y
	inline int GetPixelRed(int x, int y) { return (pixel[x + (y * width)] >> 24) & 0xFF; }
	
	// Returns green pixel value from coordinates x and y
	inline int GetPixelGreen(int x, int y) { return (pixel[x + (y * width)] >> 16) & 0xFF; }
	
	// Returns blue pixel value from coordinates x and y
	inline int GetPixelBlue(int x, int y) { return (pixel[x + (y * width)] >> 8) & 0xFF; }
	
	// Returns alpha value from coordinates x and y
	inline int GetPixelAlpha(int x, int y) { return (pixel[x + (y * width)] >> 0) & 0xFF; }


	//
	inline void SetPixel(int x, int y, int value) {	pixel[x + (y * width)] = value;	}
	
	// Set red pixel value on coordinates x and y
	inline void SetPixelRed(int x, int y, int value) { pixel[x + (y * width)] |= (value & 0xFF) << 24; }
	
	// Set green pixel value on coordinates x and y
	inline void SetPixelGreen(int x, int y, int value) { pixel[x + (y * width)] |= (value & 0xFF) << 16; }
	
	// Set blue pixel value on coordinates x and y
	inline void SetPixelBlue(int x, int y, int value) { pixel[x + (y * width)] |= (value & 0xFF) << 8; }
	
	// Set alpha value on coordinates x and y
	inline void SetPixelAlpha(int x, int y, int value) { pixel[x + (y * width)] |= (value & 0xFF) << 0; }

};

#endif