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
  void identity(cv::Mat* matrix);
  void softmax(cv::Mat* matrix);

 protected:
 private:
  float findMaxElementValue(cv::Mat* matrix);
};

#endif  // OUTPUTLAYER_H_
