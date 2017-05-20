/**
 * ActivationFunction.h<br>
 * Copyright
 *
 */

#ifndef ACTIVATIONFUNCTION_H_
#define ACTIVATIONFUNCTION_H_

#include <opencv2/core.hpp>

class ActivationFunction {
 public:
  //! Constractor
  ActivationFunction();
  //! Destructor
  virtual ~ActivationFunction();
  void sigmoid(cv::Mat* matrix);

  void step(cv::Mat* matrix);

 protected:
 private:
};

#endif  // ACTIVATIONFUNCTION_H_
