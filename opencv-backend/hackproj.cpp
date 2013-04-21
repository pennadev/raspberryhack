#include <iostream>
#include <map>
#include <string>
#include "Detection.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <exception>
#include "opencv2/objdetect/objdetect.hpp"
#include <boost/filesystem.hpp>
#include "FileUtils.h"

using namespace cv;

int main(int argc, char *argv[])
{
	//prase args
	for(int i = 1; i < argc; i++) {
		std::cout << argv[i] << std::endl;
	}
	Mat a;
	
	std::vector<Mat> elementArray; 
	DirMap_t dirMap = getDirMap("/home/pi/hackproj/python-server/python/uploads/vadeara/");
	std::cout<< "Begin to process " << std::endl;
	Detection detection;
	int i = 0;
	for(DirMap_t::iterator iter = dirMap.begin(); iter != dirMap.end(); ++iter)
	{
		i++;
		auto k =  iter->first;
		auto path = iter->second;
		std::cout <<  k << std::endl;	
		std::cout <<  path << std::endl;

		std::cout<<"Processing" << path.string() << std::endl;
		Mat image = imread(path.string());
		detection.getFaces(image);
		std::stringstream a;
		a << i;
		imwrite("home/pi/hackproj/processed_images" + a.str() + ".jpg" , image);
		std::cout << "Wrote file" << std::endl;
	}

	return 0;
}