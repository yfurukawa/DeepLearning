/**
 * OutputLayer.h<br>
 * Copyright
 *
 */

#ifndef OUTPUTLAYER_H_
#define OUTPUTLAYER_H_

#include <opencv2/core.hpp>

class OutputLayer {
 public:
  //! Constractor
  OutputLayer();
  //! Destructor
  virtual ~OutputLayer();
  cv::Mat identity(const cv::Mat& matrix);
  cv::Mat softmax(const cv::Mat& matrix);

 protected:
 private:
  float findMaxElementValue(const cv::Mat& matrix);
};

#endif  // OUTPUTLAYER_H_
