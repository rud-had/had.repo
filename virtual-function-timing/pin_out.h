/*
 * FigureFunc.h
 *
 *  Created on: Oct 12, 2015
 *      Author: rmerriam
 */

#ifndef DIGI_OUT_H_
#define DIGI_OUT_H_

enum PinType {
	eToggle, eAnalog
};
//---------------------------------------------------------------------------------------------------------------------
struct PinOut {
	enum PinType pin_type;
	const unsigned int pin;
};
//---------------------------------------------------------------------------------------------------------------------
typedef const struct PinOut* const PinOutPtr;

void toggle_out(const PinOutPtr p);
void analog_out(const PinOutPtr p);

void output_all();
void output_by_func();
void output_pin(const unsigned int i);

extern PinOutPtr pin_out_ptr;

#endif /* DIGI_OUT_H_ */
