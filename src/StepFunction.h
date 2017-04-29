/**
 * StepFunction.h<br>
 * Copyright
 *
 */

#ifndef STEPFUNCTION_H_
#define STEPFUNCTION_H_

class StepFunction {
 public:
  //! Constractor
  StepFunction();
  //! Destructor
  virtual ~StepFunction();
  double calc( double x );

 protected:
 private:
};

#endif  // STEPFUNCTION_H_
