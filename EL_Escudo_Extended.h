/*
EL_Escudo.h - EL Escudo library
Written by Ryan Owens for SparkFun Electronics
with additions by Paul Krakow

This library is released under the 'Beer Me' license, so use it however you
wish. Just buy me a beer if we ever meet!
*/

#ifndef EL_Escudo_Extended_h
#define EL_Escuod_Extended_h

#include <inttypes.h>

#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define H 9
#define STATUS 10
#define pulse_width 10

class EL_EscudoClass
{
  public:
    void on(char);
    void off(char);
void all_on(void);
void all_off(void);
void fade_in(char);
void fade_out(char);
void variable_fade_in(char, int);
void variable_fade_out(char, int);
void pulse(char);
};

extern EL_EscudoClass EL;

#endif