/*
 * TestFrame.h
 *
 *  Created on: Oct 12, 2015
 *      Author: rmerriam
 */

#ifndef TESTFRAME_H_
#define TESTFRAME_H_
#include "Arduino.h"

class TestFrame {
public:
	inline TestFrame(const unsigned int iterations = 10000) :
			mStartTime(), mInterval(), mReps(iterations) {
	}

	inline void calcInterval() {
		mInterval = micros() - mStartTime;
	}

	inline void emitTime() {
		Serial.println(mInterval / float(mReps), 2);
	}

	inline void getStartTime() {
		mStartTime = micros();
	}

private:
	unsigned long mStartTime;
	unsigned long int mInterval;
	const unsigned int mReps;
};
#endif

