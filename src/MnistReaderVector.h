/**
 * MnistReaderVector.h<br>
 * Copyright
 *
 */

#ifndef MNISTREADERVECTOR_H_
#define MNISTREADERVECTOR_H_

#include "MnistReaderCore.h"

class MnistReaderVector {
 public:
  //! Constractor
  MnistReaderVector();
  //! Destructor
  virtual ~MnistReaderVector();
  void readMnist(const std::string& filename);

 protected:
 private:
  std::vector<std::vector<double> > vec;
  MnistReaderCore readerCore;
};

#endif  // MNISTREADERVECTOR_H_
