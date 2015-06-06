//Copyright (C) 2014-2015  Corwin Hansen
#include "math.h"

FRACTION fltocfr(FLOAT frac, UINT denom, FLOAT *diff){//convert float to closest fraction with max denominator and difference in ratio to 1 / denom to fill
	FRACTION result;//result to return
	if (uinttoint(denom) == inttoInt(0)){
		if (giveerror) printf("divided by 0 error\n");
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

FRACTION fltofr(FLOAT frac, UINT denom, FLOAT *diff){//convert float to fraction 
	FRACTION current;//current fraction
	FLOAT currdiff;//current difference
	unsigned long int i;//counter
	for (i = 1; i != 0; i++){//for each possible denominator
		if (i == 0) break;//break out if looped over everything
		current.d = inttoInt(i);//set denominator
		current.n = fltoint(addfl(multfl(frac, current.d), fltoFl(0.5)));//get numerator
		currdiff = subfl(frtofl(current), frac);//get difference
		if (absfl(currdiff) == 0){//if current difference is smaller or it is a first loop
			*diff = fltoFl(0);//set difference to 0
			return current;//return current value
		}
	}
	return fltocfr(frac, denom, diff);//get closest fraction if there was no exact fraction
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

FLOAT strtofl(const char *str){//convert string to float
	return atof(str);//convert to float
}

INT strtoint(const char *str){//convert string to int
	return  atol(str);//convert to long int
}

FRACTION strtofr(const char *str){//convert string to fractions
	char val_1[VAL_LENGTH];
	strcpy(val_1, str);
	FRACTION result;//result to return
	char *val_2 = strtok(val_1, "  /\r\n\t;\0");//get numerator
	if (str == NULL){//if there was nothing
		if (giveerror) printf("There was no valid fraction in the string \"%s\"\n", str);//give error message
		result.d = 0;//set both to 0 for error
		result.n = 0;
		return result;//return result
	}
	result.n = strtoint(val_2);//set numerator
	val_2 = strtok(NULL, "  /\r\n\t;");//get denominator
	if (val_2 == NULL){//if there was nothing
		if (giveerror) printf("There was no valid fraction in the string \"%s\"\n", str);//give error message
		result.d = 0;//set both to 0 for error
		result.n = 0;
		return result;//return result
	}
	result.d = strtoint(val_2);//set denominator
	if (Fltofl(result.d) == 0){
		if (giveerror) printf("divided by 0 error\n");//give error message
		result.d = 0;//set both to 0 for error
		result.n = 0;
	}
	return result;//return result
}

int equalsfl(FLOAT a, FLOAT b){//if a equals b
	return a == b;//get if a equals b
}

int equalsint(INT a, INT b){//if a equals b
	return a == b;//get if a equals b
}

int equalsfr(FRACTION a, FRACTION b){//if a equals b
	return equalsfl(frtofl(a), frtofl(b));//if each frction as float equals each other
}