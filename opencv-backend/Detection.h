#ifndef DETECT_H_
#define DETECT_H_

#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include <opencv2/core/core.hpp> 
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;


struct DataElement {
	DataElement(Mat data, std::string path) : path(path) {
		this->data = data;

	}

	std::string path;
	Mat data;
	std::vector<Rect> faces;
};


class Detection { 
public:
	void getFaces(Mat& a);
	void getFaces(DataElement& element);

	Detection();

private:
	const std::string face_cascade_name;
	CascadeClassifier face_cascade;

};

#endif