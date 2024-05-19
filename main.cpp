#include <CImg.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace cimg_library;

char getASCII(CImg<float>::iterator it) {
        if (*it < 10) {
                return '@';
        } else if (*it < 20) {
                return '#';
        } else if (*it < 30) {
                return 'M';
        } else if (*it < 40) {
                return 'B';
        } else if (*it < 50) {
                return '8';
        } else if (*it < 60) {
                return '&';
        } else if (*it < 70) {
                return 'W';
        } else if (*it < 80) {
                return '%';
        } else if (*it < 90) {
                return 'h';
        } else if (*it < 100) {
                return 'a';
        } else if (*it < 110) {
                return 'k';
        } else if (*it < 120) {
                return '=';
        } else if (*it < 130) {
                return '+';
        } else if (*it < 140) {
                return ':';
        } else if (*it < 150) {
                return '-';
        } else if (*it < 160) {
                return '.';
        } else if (*it < 170) {
                return ' ';
        } else if (*it < 180) {
                return ' ';
        } else if (*it < 190) {
                return ' ';
        } else if (*it < 200) {
                return ' ';
        } else if (*it < 210) {
                return ' ';
        } else if (*it < 220) {
                return ' ';
        } else if (*it < 230) {
                return ' ';
        } else if (*it < 240) {
                return ' ';
        } else if (*it < 250) {
                return ' ';
        } else {
                return ' ';
	}
}

int main() {
	char uinp[128];
	std::cout << "File name, with file extension: ";
	scanf("%[^\r\n]", uinp);
	std::cin.get();

	char uinp_o[128];
	std::cout << "Output file name (will be a .txt, regardless of name): ";
	scanf("%[^\r\n]", uinp_o);

	std::ofstream file;
	file.open(strcat(uinp_o,".txt"));

	CImg<float> image(uinp);
	std::cout << "Image Dimensions: " << image.width() << " cols & " << image.height() << " rows." << std::endl;
	std::cout << "The image has: " << image.spectrum() << " colors. (1=greyscale, 3=rgb)" << std::endl;
	std::cout << "Image Size: " << image.size() << std::endl;

	if ( image.width() > 100 || image.height() > 100 ) {
		image = image.resize(100,50);
		std::cout << "Image resized..." << std::endl;
		std::cout << "Image Dimensions: " << image.width() << " cols & " << image.height() << " rows." << std::endl;
		std::cout << "The image has: " << image.spectrum() << " colors. (1=greyscale, 3=rgb)" << std::endl;
		std::cout << "Image Size: " << image.size() << std::endl;	
	}

	std::cout << "Writing to file..." << std::endl;
	int rowCounter = 0;
	std::string color = "Red";
	bool printColor = true;

	for (CImg<float>::iterator it = image.begin(); it < image.end(); it++) {
		// If at start of new color, display that
		if (printColor == true) {
			file << color << ":" << std::endl;
			printColor = !printColor;
		}
		file << getASCII(it);
		rowCounter++;
		if (rowCounter % image.width() == 0) {
			file << std::endl;
		}

		// If image is RGB and we have reached the end of one color, print new line for next color
		if (image.spectrum() > 1 && rowCounter % ( image.width() * image.height() ) == 0) {
			file << std::endl;
			printColor = !printColor;
			if (color == "Red") {
				color = "Green";
			} else {
				color = "Blue";
			}
		}
	}

	file.close();
	std::cout << "Finished writing to file...File closed." << std::endl;

	return 0;
}



