/*
 * displays_exercise01.c++
 *
 *  Created on: 03.11.2017
 *      Author: Veronika Kohler, Florian Grimm
 */


#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <stdio.h>
#include <math.h>

using namespace cv;

int main( int argc, char** argv ){

	// Status message
	printf("--- Display - exercise01 --- \n");

	// Declare some Mat variable for the image
	Mat image;

	// Read provided image of exercise01
	image = imread(argv[1], IMREAD_COLOR);

	// Check if successful
	if(argc != 2 || !image.data){
		printf("No image data \n");
		return -1;
	}

	// ----- TASK 1.1 Display an image with OpenCV -----
	namedWindow("Display Image", CV_WINDOW_AUTOSIZE);
	imshow("Display Image", image);
	waitKey(0);

	// ----- TASK 1.2 Gamma Correction and Absolute Difference Image -----

	// ___ SUBTASK: Gamma Correction ___
	// Status message
	printf("Gamma Correction...");

	// Some variables
	Mat gammaCorImage = image.clone();
	float gammaCor = 0.5;
	float intensity;

	// Processing gamma correction
	for(int x = 0; x < image.cols; x++){
		for(int y = 0; y < image.rows; y++){
			for(int c = 0; c < 3; c++){

				// Get intensity of current pixel
				intensity = image.at<Vec3b>(y,x)[c];

				// Apply gamma correction and save into image file
				gammaCorImage.at<Vec3b>(y,x)[c] = pow(intensity/255.0f, gammaCor) * 255.0f;
			}
		}
	}

	// Save result
	imwrite("gammaCorImg.png", gammaCorImage);

	// Status message
	printf("done \n");

	// ___ SUBTASK: Absolute Difference ___
	// - Status message
	printf("Absolute difference...");

	// Some variables
	Mat absDiffImage;

	// Processing absolute difference
	absdiff(image, gammaCorImage, absDiffImage);

	// Save result
	imwrite("absDiffImage.png", absDiffImage);

	// Status message
	printf("done \n");

	// ----- Show results
	Mat resultImage(Size(image.cols * 3, image.rows), CV_8UC3);
	image.copyTo(resultImage(Rect(0, 0, image.cols, image.rows)));
	gammaCorImage.copyTo(resultImage(Rect(image.cols, 0, image.cols, image.rows)));
	absDiffImage.copyTo(resultImage(Rect(image.cols * 2, 0, image.cols, image.rows)));
	namedWindow("Display results with Gamma Correction 0.5 and Absolute Difference (image, gamma correction, absolute difference)", CV_WINDOW_AUTOSIZE);
	imshow("Display results with Gamma Correction 0.5 and Absolute Difference (image, gamma correction, absolute difference)", resultImage);
	waitKey(0);

	return 0;
}
