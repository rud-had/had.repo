/*
 * afile.c
 *
 *  Created on: Oct 12, 2015
 *      Author: rmerriam
 */
#include "pin_out.h"

#include "Arduino.h"
//---------------------------------------------------------------------------------------------------------------------
struct PinOut p_out11 = { eAnalog, 11 };
struct PinOut p_out13 = { eToggle, 13 };

static PinOutPtr io_pins[] = { &p_out13, &p_out11, &p_out13, &p_out11, &p_out13, &p_out11, &p_out13, &p_out11, &p_out13,
		&p_out11, };
const size_t io_Pins_size = 10;

PinOutPtr pin_out_ptr = &p_out13;
//---------------------------------------------------------------------------------------------------------------------
typedef void (*pin_out_func)(const PinOutPtr);
pin_out_func func_ptrs[] = { &toggle_out, &analog_out };
//---------------------------------------------------------------------------------------------------------------------
void output_by_func() {
	size_t i;
	for (i = 0; i < io_Pins_size; i++) {
		PinOutPtr p = io_pins[i];
		func_ptrs[p->pin_type](p);
	}
}
//---------------------------------------------------------------------------------------------------------------------
void toggle_out(const PinOutPtr p) {
	digitalWrite(p->pin, !digitalRead(p->pin));
}
//---------------------------------------------------------------------------------------------------------------------
void analog_out(const PinOutPtr p) {
	analogWrite(p->pin, 200);
}
//---------------------------------------------------------------------------------------------------------------------
void output_pin(const unsigned int i) {

	PinOutPtr p = io_pins[i];

	switch (p->pin_type) {
	case eToggle:
		toggle_out(p);
		break;

	case eAnalog:
		analog_out(p);
		break;

	default:
		break;
	}
}
//---------------------------------------------------------------------------------------------------------------------
void output_all() {
	size_t i;
	for (i = 0; i < io_Pins_size; i++) {
		output_pin(i);
	}
}

