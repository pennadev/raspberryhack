#include <iostream>
#include <map>
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

//#include <opencv2/highgui/highgui.hpp>
using namespace cv;

int main(int argc, char *argv[])
{
	//prase args
	for(int i = 1; i < argc; i++) {
		std::cout << argv[i] << std::endl;
	}

	Mat a  = imread(std::string("/home/pi/testimg.jpg"), 1);


	imwrite(std::string("/home/pi/testimg.jpg", a);

	return 0;
}