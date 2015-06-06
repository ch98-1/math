//Copyright (C) 2015  Corwin Hansen
#ifndef MATH_H//include protection
	#define MATH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdint.h>

#define VAL_LENGTH 256//length of val string
#define FLOAT_STR_PRECISION "%.15f"//precision of float when converted to string

#define UINT unsigned long int
#define INT long int
#define FRACTION fraction
#define FLOAT double

int giveerror;//if printing error or not

typedef struct{
	INT n, d;//numerator and denominator
}fraction;

FRACTION fltocfr(FLOAT frac, UINT denom, FLOAT *diff);//convert float to closest fraction with max denominator and difference in ratio to 1/denom to fill
FRACTION fltofr(FLOAT frac);//convert float to fraction
FLOAT frtofl(FRACTION frac);//convert fraction to float
void fltostr(char *str, FLOAT fl);//convert float to string
void inttostr(char *str, INT in);//convert int to string
void frtostr(char *str, FRACTION fr);//convert fraction to string
FLOAT strtofl(const char *str);//convert string to float
INT strtoint(const char *str);//convert string to int
FRACTION strtofr(const char *str);//convert string to fraction
FLOAT inttofl(INT fl);//convert int to float
INT fltoint(FLOAT fl);//convert float to int
UINT inttouint(INT i);//convert int to unsigned int
INT uinttoint(UINT i);//convert unsigned int to int
FLOAT addfl(FLOAT a, FLOAT b);//add a to b
FLOAT subfl(FLOAT a, FLOAT b);//subtract b from a
FLOAT multfl(FLOAT a, FLOAT b);//multiply a by b
FLOAT divfl(FLOAT a, FLOAT b);//divide a by b
long int Inttoint(INT i);//convert INT to actual int
double Fltofl(FLOAT fl);//convert FLOAT to actual float
INT inttoInt(long int i);//convert actual int to INT
FLOAT fltoFl(double fl);//convert actual float to FLOAT
INT absint(INT i);//get absolute value of int
FLOAT absfl(FLOAT fl);//get absolute value of float
int equalsfl(FLOAT a, FLOAT b);//if a equals b
int equalsint(INT a, INT b);//if a equals b
int equalsfr(FRACTION a, FRACTION b);//if a equals b


#endif