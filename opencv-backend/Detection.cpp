#include <vector>
#include <iostream>
#include "Detection.h"

Detection::Detection() : face_cascade_name("/home/pi/hackproj/opencv-backend/haarcascade_frontalface_alt.xml")

{
	if(!face_cascade.load(face_cascade_name)) {
		std::cout << "Can't load " + face_cascade_name << std::endl;
	}
}
void Detection::getFaces(Mat& a) {
	std::vector<Rect> faces;
	Mat frameGray;
	cvtColor( a, frameGray, CV_BGR2GRAY );
	equalizeHist( frameGray, frameGray );

	//-- Detect faces
	face_cascade.detectMultiScale( frameGray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
	std::cout << "begin loop "<< std::endl;

	for( int i = 0; i < faces.size(); i++ )
	{
		Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
		rectangle(a, faces[i], Scalar(255, 0, 0));
		//ellipse( a, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
		std::cout << "iteration " + i << std::endl;
	}
	std::cout << "end loop "<< std::endl;

}
