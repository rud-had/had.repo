/*
 * OutputDeviceAbstract.h
 *
 *  Created on: Oct 20, 2015
 *      Author: rmerriam
 */

#ifndef PINOUTPUTABSTRACT_CPP_
#define PINOUTPUTABSTRACT_CPP_
//---------------------------------------------------------------------------------------------------------------------
class PinOutputAbstract {
public:
	PinOutputAbstract(const unsigned int pin) :
			mPinNum { pin } {
		pinMode(mPinNum, OUTPUT);
	}
	virtual ~PinOutputAbstract() {
	}

	virtual void output() const = 0;

	static void outputPins();

protected:
	const unsigned int mPinNum;

	static PinOutputAbstract* mOutpuDevices[];
	static const size_t mOutDevicesCnt;
};
using PinPtr = PinOutputAbstract*;

#endif /* PINOUTPUTABSTRACT_CPP_ */
