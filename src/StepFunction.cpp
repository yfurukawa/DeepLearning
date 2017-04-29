/*
 * Copyright
 *
*/
#include "./StepFunction.h"

StepFunction::StepFunction() {
}

StepFunction::~StepFunction() {
}

double StepFunction::calc( double x) {
	if( x > 0.0 ) {
		return 1.0;
	}
	else {
		return 0.0;
	}
}
