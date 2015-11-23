#include "Arduino.h"

// Do not remove the include below
#include "TimingTest.h"

#include "DigitalOut.h"
#include "AnalogOut.h"

extern "C" {
#include "pin_out.h"
}

#include "TestFrame.h"
//---------------------------------------------------------------------------------------------------------------------
// see if build is for Arduino or host OS
#if __LP64__
// host OS with much faster processor so increase the iterations
const size_t iterations = 1000000;
#else
const size_t iterations = 10000;
#endif
//---------------------------------------------------------------------------------------------------------------------
const long int serial_bps = 115200;

TestFrame tf(iterations);
//---------------------------------------------------------------------------------------------------------------------
void setup() {
	Serial.begin(serial_bps);
	while (!Serial) {
		; // wait for serial port to connect. Needed for native USB
	}
}
//---------------------------------------------------------------------------------------------------------------------
void time_simple_calls() {

	//---------------------------------------------
	// test C function direct call
	tf.getStartTime();

	for (size_t i = 0; i < iterations; i++) {
		toggle_out (pin_out_ptr);
	}

	tf.calcInterval();
	tf.emitTime();

	//---------------------------------------------
	// test C++ member, direct call
	tf.getStartTime();

	for (size_t i = 0; i < iterations; i++) {
		pin13.output();
	}

	tf.calcInterval();
	tf.emitTime();

	//---------------------------------------------
	// test C++ member virtual call
	tf.getStartTime();

	for (size_t i = 0; i < iterations; i++) {
		pin13_ptr->output();
	}

	tf.calcInterval();
	tf.emitTime();
}
//---------------------------------------------------------------------------------------------------------------------
void time_list_calls() {

	//---------------------------------------------
	// test C function direct call
	tf.getStartTime();

	for (size_t i = 0; i < iterations; i++) {
		output_all();
	}

	tf.calcInterval();
	tf.emitTime();

	//---------------------------------------------
	// test C function ptr call
	tf.getStartTime();

	for (size_t i = 0; i < iterations; i++) {
		output_by_func();
	}

	tf.calcInterval();
	tf.emitTime();

	//---------------------------------------------
	// test C++ member virtual via member
	tf.getStartTime();

	for (size_t i = 0; i < iterations; i++) {
		PinOutputAbstract::outputPins();
	}

	tf.calcInterval();
	tf.emitTime();
}
//---------------------------------------------------------------------------------------------------------------------
void loop() {

	time_simple_calls();
	time_list_calls();
	Serial.println();

}

