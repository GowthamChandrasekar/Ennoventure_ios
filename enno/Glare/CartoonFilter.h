//
//  CartoonFilter.h
//  OpenCV Tutorial
//
//  Created by BloodAxe on 7/19/12.
//  Copyright (c) 2012 computer-vision-talks.com. All rights reserved.
//

#ifndef OpenCV_Tutorial_CartoonFilter_h
#define OpenCV_Tutorial_CartoonFilter_h

#include "SampleBase.h"

class CartoonFilter : public SampleBase
{
    virtual std::string getName() const;
    
    virtual std::string getSampleIcon() const;
    
    //! Returns a detailed sample description
    virtual std::string getDescription() const;
      
    //! Processes a frame and returns output image
    virtual std::string processFrame(const cv::Mat& inputFrame, cv::Mat& outputFrame);

  private:
    cv::Mat gray, edges;

};


#endif
