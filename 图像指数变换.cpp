#include <iostream>
#include<opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include"opencv2/imgproc/imgproc.hpp"
#include <stdio.h>

using namespace std;
using namespace cv;

Mat myExpTrans(Mat img, float gama,float esp) {
	Mat res(img.rows, img.cols, img.type());
	
	if (img.channels() == 1) {
		vector<vector<int> > tabel(img.rows, vector<int>(img.cols));
		for (int x = 0; x < img.rows; x++) {
			for (int y = 0; y < img.cols; y++) {
				res.at<uchar>(x, y) = uchar(pow(img.at<uchar>(x, y) / float(255) + esp, gama) * 255);
			}
		}

	}
	else {
		for (int c = 0; c < img.channels(); c++) {
			for (int x = 0; x < img.rows; x++) {
				for (int y = 0; y < img.cols; y++) {
					res.at<Vec3b>(x, y)[c] = uchar(pow(img.at<Vec3b>(x, y)[c] / float(255) + esp, gama) * 255);
				}
			}
		}
	}
	return res;
}

int main() {
	Mat img = imread("C://Users//Chrysanthemum//Desktop//1.png");
	float gama = 5;
	float esp = 0;

	Mat res = myExpTrans(img, gama,esp);

	imshow("origin pic", img);
	imshow("result pic", res);
	waitKey();
}