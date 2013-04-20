#include <vector>
#include <opencv2/core/core.hpp> 
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
class Detection { 
public:
	void getFaces(Mat& a);
	Detection();

private:
	const std::string face_cascade_name;
	CascadeClassifier face_cascade;
};