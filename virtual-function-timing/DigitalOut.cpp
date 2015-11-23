/*
 * Figure.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: rmerriam
 */
#include "Arduino.h"

#include "DigitalOut.h"

//---------------------------------------------------------------------------------------------------------------------
void DigitalOut::output() const {
    digitalWrite(mPinNum, !digitalRead(mPinNum));
}

