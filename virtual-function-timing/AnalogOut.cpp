/*
 * AnalogOut.cpp
 *
 *  Created on: Oct 20, 2015
 *      Author: rmerriam
 */

#include "Arduino.h"
#include "AnalogOut.h"
//---------------------------------------------------------------------------------------------------------------------

void AnalogOut::output() const {
	analogWrite(mPinNum, 100);
}
