
#include <iostream>
#include "ContourDetectionSample.h"
#include <UIKit/UIKit.h>
#include <opencv2/core/core_c.h>
using namespace std;

//! Gets a sample name
std::string ContourDetectionSample::getName() const
{
    return "Blur detection";
}

//! Returns a detailed sample description
std::string ContourDetectionSample::getDescription() const
{
    return "Blur detection using OpenCV.";
}

std::string ContourDetectionSample::getSampleIcon() const
{
    return "ContourDetectionSampleIcon.png";
}

//! Processes a frame and returns output image
std::string ContourDetectionSample::processFrame(const cv::Mat& inputFrame, cv::Mat& outputFrame)
{

    cv::Mat m;
    cv::Mat inputImage(inputFrame);
    getGray(inputImage, gray);
    cv::Mat gray;
    cv::cvtColor( inputImage, gray, cv::COLOR_RGB2GRAY );
    //Cool, let's compute the laplacian of the gray image:
    cv::Mat laplacianImage;
    cv::Laplacian( gray, laplacianImage, CV_64F );
    //Prepare to compute the mean and standard deviation of the laplacian:
    cv::Scalar mean, stddev;
    cv::meanStdDev( laplacianImage, mean, stddev, cv::Mat() );

    //Let’s compute the variance:
    double variance = stddev.val[0] * stddev.val[0];
    double blurThreshold = 37.0000;
    inputFrame.copyTo(outputFrame);
    
    if ( variance <= blurThreshold ) {
        return "Input image is blurry!";
    } else {
        return "Input image is sharp";
    }
    
    


}
