/**
 * MnistReaderOpenCV.h<br>
 * Copyright
 *
 */

#ifndef MNISTREADEROPENCV_H_
#define MNISTREADEROPENCV_H_

#include <vector>
#include <opencv2/core.hpp>
#include "MnistReaderCore.h"

class MnistReaderOpenCV {
 public:
  //! Constractor
  MnistReaderOpenCV();
  //! Destructor
  virtual ~MnistReaderOpenCV();
  std::vector<cv::Mat> readMnist(const std::string& filename);
  std::vector<double> readMnistLabel(const std::string& filename);

 protected:
 private:
  std::vector<cv::Mat> vec;
  MnistReaderCore readerCore;
};

#endif  // MNISTREADEROPENCV_H_
