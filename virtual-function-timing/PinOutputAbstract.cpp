/*
 * OutputDeviceAbstract.cpp
 *
 *  Created on: Oct 20, 2015
 *      Author: rmerriam
 */
#include "Arduino.h"
#include "PinOutputAbstract.h"
#include "DigitalOut.h"
#include "AnalogOut.h"

//---------------------------------------------------------------------------------------------------------------------
DigitalOut pin13(13);
AnalogOut pin11(11);

PinPtr PinOutputAbstract::mOutpuDevices[] { &pin13, &pin11, &pin13, &pin11, &pin13, &pin11, &pin13, &pin11, &pin13,
		&pin11, };
PinPtr pin13_ptr = &pin13;
//---------------------------------------------------------------------------------------------------------------------
void PinOutputAbstract::outputPins() {
	for (auto p : mOutpuDevices) {
		p->output();
	}
}
