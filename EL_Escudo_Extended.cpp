/*
EL_Escudo_Extended.cpp - EL Escudo Extended library
Written by Ryan Owens for SparkFun Electronics
with additions by Paul Krakow

This library is released under the 'Beer Me' license, so use it however you
wish. Just buy me a beer if we ever meet!
*/

/******************************************************************************
* Includes
******************************************************************************/

#include "Arduino.h"
#include "EL_Escudo_Extended.h"

/******************************************************************************
* Definitions
******************************************************************************/

/******************************************************************************
* Constructors
******************************************************************************/

/******************************************************************************
* User API
******************************************************************************/

void EL_EscudoClass::on(char channel)
{
pinMode(channel, OUTPUT);
digitalWrite(channel, HIGH);
}

void EL_EscudoClass::off(char channel)
{
pinMode(channel, INPUT);
}

void EL_EscudoClass::all_on(void)
{
for(int i=0; i<4; i++){
EL.on(i*2+A);
EL.on(i*2+1+A);
delayMicroseconds(20);
EL.off(i*2+A);
EL.off(i*2+1+A);
}
}

void EL_EscudoClass::all_off(void)
{
for(int i=A; i<10; i++)EL.off(i);
}

void EL_EscudoClass::fade_in(char channel)
{
for(int brightness=0; brightness<=pulse_width; brightness++){
for(int duration=0; duration<5; duration++){
EL.on(channel);
delay(brightness);
EL.off(channel);
delay(pulse_width-brightness);
}
}
EL.on(channel);
}

void EL_EscudoClass::fade_out(char channel)
{
for(int brightness=pulse_width; brightness>=0; brightness--){
for(int duration=0; duration<5; duration++){
EL.on(channel);
delay(brightness);
EL.off(channel);
delay(pulse_width-brightness);
}
}
}

void EL_EscudoClass::pulse(char channel)
{
EL.fade_in(channel);
EL.fade_out(channel);
}

void EL_EscudoClass::variable_fade_in(char channel, int time)
{
for(int brightness=0; brightness<=pulse_width; brightness++){
for(int duration=0; duration<time; duration++){
EL.on(channel);
delay(brightness);
EL.off(channel);
delay(pulse_width-brightness);
}
}
EL.on(channel);
}

void EL_EscudoClass::variable_fade_out(char channel, int time)
{
for(int brightness=pulse_width; brightness>=0; brightness--){
for(int duration=0; duration<time; duration++){
EL.on(channel);
delay(brightness);
EL.off(channel);
delay(pulse_width-brightness);
}
}
}

EL_EscudoClass EL;