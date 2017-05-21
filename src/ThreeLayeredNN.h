/**
 * ThreeLayeredNN.h<br>
 * Copyright
 *
 */

#ifndef THREELAYEREDNN_H_
#define THREELAYEREDNN_H_

#include <map>
#include <string>
#include <opencv2/core.hpp>

class ThreeLayeredNN {
 public:
  //! Constractor
  ThreeLayeredNN();
  //! Destructor
  virtual ~ThreeLayeredNN();
  void initialize();
  void forward();
 protected:
 private:
  std::map<std::string, cv::Mat > network;
};

#endif  // THREELAYEREDNN_H_
