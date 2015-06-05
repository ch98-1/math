//Copyright (C) 2014-2015  Corwin Hansen
#include "math.h"

FRACTION fltofr(FLOAT frac, UINT denom, FLOAT *diff){//convert float to fraction with max denominator and difference in ratio to 1 / denom to fill
	FRACTION result;//result to return
	if (uinttoint(denom) == inttoInt(0)){
		printf("divided by 0 error\n");
		result.n = 0;//set as 0/0
		result.d = 0;
		return result;//return the result
	}
	FRACTION current;//current fraction
	FLOAT currdiff;//current difference
	unsigned long int i;//counter
	for (i = (unsigned long)Inttoint(denom); i > 0; i--){//for each possible denominator
		current.d = inttoInt(i);//set denominator
		current.n = fltoint(addfl(multfl(frac, current.d), fltoFl(0.5)));//get numerator
		currdiff = multfl(subfl(frtofl(current), frac), denom);//get difference in ratio to 1 / denominator
		if (absfl(currdiff) <= absfl(*diff) || i == (unsigned long)Inttoint(denom)){//if current difference is smaller or it is a first loop
			result = current;//set to current values
			*diff = currdiff;
		}
	}
	return result;
}

FLOAT frtofl(FRACTION frac){//convert fraction to float
	return divfl(frac.n, frac.d);//return result
}

void fltostr(char *str, FLOAT fl){//convert float to string
	sprintf(str, FLOAT_STR_PRECISION, fl);//get float
}

void inttostr(char *str, INT in){//convert int to string
	sprintf(str, "%ld", in);//get int
}

void frtostr(char *str, FRACTION fr){//convert fraction to string
	char str_1[VAL_LENGTH], str_2[VAL_LENGTH];//2 string for each integer
	inttostr(str_1, fr.n);//get numerator
	inttostr(str_2, fr.d);//get denominator
	sprintf(str, "%s/%s", str_1, str_2);//get fraction
}

FLOAT inttofl(INT fl){//convert int to float
	return (FLOAT)fl;//typecast
}

INT fltoint(FLOAT fl){//convert float to int
	return (INT)fl;//typecast
}

UINT inttouint(INT i){//convert int to unsigned int
	return (UINT)i;//typecast
}

INT uinttoint(UINT i){//convert unsigned int to int
	return (INT)i;//typecast
}

FLOAT addfl(FLOAT a, FLOAT b){//add a to b
	return a + b;
}

FLOAT subfl(FLOAT a, FLOAT b){//subtract b from a
	return a - b;
}

FLOAT multfl(FLOAT a, FLOAT b){//multiply a by b
	return a * b;
}

FLOAT divfl(FLOAT a, FLOAT b){//divide a by b
	return a / b;
}

long int Inttoint(INT i){//convert INT to actual int
	return i;//return itself
}

double Fltofl(FLOAT fl){//convert FLOAT to actual float
	return fl;//return itself
}

INT inttoInt(long int i){//convert actual int to INT
	return i;//return itself
}

FLOAT fltoFl(double fl){//convert actual float to FLOAT
	return fl;//return itself
}

INT absint(INT i){//get absolute value of int
	return labs(i);//get absolute value
}

FLOAT absfl(FLOAT fl){//get absolute value of float
	if (fl < 0)//if negative
		return subfl(fltoFl(0), fl);//get it to positive
	else//if positive
		return fl;//return the same number
}