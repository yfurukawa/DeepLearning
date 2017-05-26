/**
 * MnistReaderCore.h<br>
 * Copyright
 *
 */

#ifndef MNISTREADERCORE_H_
#define MNISTREADERCORE_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class MnistReaderCore {
 public:
  //! Constractor
  MnistReaderCore();
  //! Destructor
  virtual ~MnistReaderCore();
  std::vector<double> readMnistLabel(const std::string& filename);
  int reverseInt (int i);

 protected:
 private:
  // std::vector<double> vecl;
};

#endif  // MNISTREADERCORE_H_
