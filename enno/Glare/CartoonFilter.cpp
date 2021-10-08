//
//  CartoonFilter.cpp
//  OpenCV Tutorial
//
//  Created by BloodAxe on 7/19/12.
//  Copyright (c) 2012 computer-vision-talks.com. All rights reserved.
//


#include <iostream>
#include "CartoonFilter.h"
#include <UIKit/UIKit.h>
#include <opencv2/core/core_c.h>
using namespace std;



std::string CartoonFilter::getName() const
{
    return "Galre Detection";
}

std::string CartoonFilter::getDescription() const
{
    return "This sample performs Galre Detection";
}

std::string CartoonFilter::getSampleIcon() const
{
    return "ContourDetectionSampleIcon.png";
}


std::string CartoonFilter::processFrame(const cv::Mat& inputFrame, cv::Mat& outputFrame)

{
    double  sigmaX = 0.0;
    double minVal;
    double maxVal;
    cv::Mat m;
    cv::Mat inputImage(inputFrame);
    getGray(inputImage, gray);
    cv::Mat gray;
    cv::cvtColor( inputImage, gray, cv::COLOR_BGR2GRAY );
    
    
//    Imgproc.cvtColor(Rgba, grayScaleGaussianBlur, Imgproc.COLOR_BGR2GRAY);
//       Imgproc.GaussianBlur(grayScaleGaussianBlur, grayScaleMinMax, new Size(11, 11), 0);
//
//
//       Imgproc.threshold(grayScaleMinMax,grayScalethresh,30,255, Imgproc.THRESH_OTSU);
//
//    //   Imgproc.erode(grayScalethresh,erodeMat,null);
//    //   Imgproc.dilate(grayScalethresh,erodeMat,null);
//       Core.MinMaxLocResult minMaxLocResultBlur = Core.minMaxLoc(grayScalethresh);
//
//       final double maxval = minMaxLocResultBlur.maxLoc.x;
//       final double minval = minMaxLocResultBlur.maxLoc.y;

    
//    cv::GaussianBlur(gray, gray, cv::Size(11,11), sigmaX);
//    cv::threshold(gray, gray, 30, 255, cv::THRESH_OTSU);
//
//    cv::minMaxLoc(gray, &minVal, &maxVal);
//    std::cout << "The maximum value is : " << &minVal << std::endl;
//    std::cout << "The maximum value is : " << &maxVal << std::endl;
//    inputFrame.copyTo(outputFrame);
//
//    if (maxVal > 0 && minVal > 0.0) {
//        return "Image is glared";
//    }else
//    {
//        return "image is not glared";
//    }
    
    
    
    cv::GaussianBlur(gray, gray, cv::Size(11,11), sigmaX);
//    cv::threshold(gray, gray, 30, 255, cv::THRESH_OTSU);
    
    cv::minMaxLoc(gray, &minVal, &maxVal);
    std::cout << "The maximum value is : " << &minVal << std::endl;
    std::cout << "The maximum value is : " << &maxVal << std::endl;
    inputFrame.copyTo(outputFrame);

    if (maxVal > 253.0 && minVal > 0.0 && minVal < 20 ) {
        return "Image is glared";
    }else
    {
        return "image is not glared";
    }

}
