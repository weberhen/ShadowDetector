#ifndef _SHADOWDETECTOR
#define _SHADOWDETECTOR


#include "opencv2/opencv.hpp"
#include "SquareDetection.hpp"
#include "MathFunctions.hpp"
#include "ImageManipulation.hpp"
#include "PlateExtraction.hpp"
#include "Histogram.hpp"
//#include "RobustMatcher.cpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using namespace cv;

typedef struct asphaltInfo{
	int average;
	int median;
	int sd;
	int porcentageAsphalt;
} structAsphaltInfo;

extern clock_t timeBetweenPlates;

extern int mouseClicks;
extern int frame;
extern Point currentClick, previewsClick;
extern Vector<Point> platesInFrame;

extern int algX;
extern int algY;
extern int algWidth;
extern int algHeight;
extern ifstream myfile;

extern int totalRealPlates;
extern int totalAlgPlates;
extern int falsePositives;
extern int falseNegatives;
extern int gotHolePlate;

Mat EraseLine(Mat img, int segmentSize, int i, int j);
Mat SurroundCar(Mat src,int i,int j,int segmentSize);
Mat CannyThreshold(Mat src, int lowThreshold);
Mat FreeDrivingSpace(Mat dst, Mat src,structAsphaltInfo *_structAsphaltInfo);
structAsphaltInfo FreeDrivingSpaceInfo(Mat src_gray);
vector<Vec4i> excludeDuplicateShadows(vector<Vec4i> lines);
vector<Vec4i> mergeLines(Mat src);
Mat TransitionToShadow(Mat input, int uBoundary);
Mat ExludeFalseShadowPixels(Mat input, Size size);
void CreateROIOfShadow(vector<Vec4i> lines, Mat input, float reductionFactor);
Mat localSTD(Mat input, Mat xi, Mat xi2, int ind);
void IsolatePlate(Mat input,int z, int x, int y);
void SearchForShadow(Mat src,int uBoundary);
int SizeOfCar(Mat *smallerImg, int y, int x);
bool PixelBelongToSegment(Mat dst, int i, int j);


#endif
