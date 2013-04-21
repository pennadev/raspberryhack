#include <vector>
#include <iostream>
#include "Detection.h"

Detection::Detection() : face_cascade_name("/home/pi/hackproj/opencv-backend/haarcascade_frontalface_alt.xml")
{
	if(!face_cascade.load(face_cascade_name)) {
		std::cout << "Can't load " + face_cascade_name << std::endl;
	}
}	

void Detection::getFaces(DataElement& element) {
	Mat& a = element.data;
//	element.faces = getFaces(a);
}	

void Detection::getFaces(Mat& a) {

	std::vector<Rect> faces;
	Mat frameGray;
	Mat frameGray2;

	cvtColor( a, frameGray, CV_BGR2GRAY );
	equalizeHist( frameGray, frameGray2 );

	face_cascade.detectMultiScale( frameGray2, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

	for( int i = 0; i < faces.size(); i++ )
	{
		rectangle(a, faces[i], Scalar(255, 0, 0));
	}
	std::cout << "end loop "<< std::endl;
}
