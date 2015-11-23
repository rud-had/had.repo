/*
 * AnalogOut.h
 *
 *  Created on: Oct 20, 2015
 *      Author: rmerriam
 */

#ifndef ANALOGOUT_H_
#define ANALOGOUT_H_

#include "PinOutputAbstract.h"
//---------------------------------------------------------------------------------------------------------------------
class AnalogOut: public PinOutputAbstract {
public:
	AnalogOut(const int pin) : PinOutputAbstract(pin) { }
	virtual ~AnalogOut() { }

	virtual void output() const;
};

#endif /* ANALOGOUT_H_ */
