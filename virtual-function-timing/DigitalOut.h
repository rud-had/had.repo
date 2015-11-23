/*
 * Figure.h
 *
 *  Created on: Oct 12, 2015
 *      Author: rmerriam
 */

#ifndef DIGITALOUT_H_
#define DIGITALOUT_H_

#include "PinOutputAbstract.h"
//---------------------------------------------------------------------------------------------------------------------
class DigitalOut: public PinOutputAbstract {

public:
	DigitalOut(const unsigned char pin) :
			PinOutputAbstract(pin) {
	}
	virtual ~DigitalOut() {
	}

	void output() const;
};
//---------------------------------------------------------------------------------------------------------------------

extern DigitalOut pin13;
extern PinPtr pin13_ptr;

#endif /* DIGITALOUT_H_ */

