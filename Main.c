//Copyright (C) 2014-2015  Corwin Hansen
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "math.h"

#define DEF_DENOM 999//defalult maximum denominator
#define STR_LENGTH 2048//length of full string

int main(int argc, char *argv[]){
	giveerror = 1;//print out all error
	char input[STR_LENGTH];//input to get
	char command[VAL_LENGTH];//command seperated from input
	char val_1[VAL_LENGTH];//vlaues to fill
	char val_2[VAL_LENGTH];
	char val_3[VAL_LENGTH];
	char val_4[VAL_LENGTH];
	char *str;//string to check for null
	while (1){
		redo:
		if (gets(input) != NULL){//get string from input and if it wasn't NULL
			str = strtok(input, " ");//get command
			if (str == NULL){//if there was nothing entered
				goto redo;//go back to start
			}
			strcpy(command, str);//copy command

			if (strcmp(command, "quit") == 0){//if quitting
				exit(EXIT_SUCCESS);//if it somehow reaches here
			}

			else if (strcmp(command, "fltocfr") == 0){//if converting float to closest fraction
				FLOAT fl;//values to fill with
				UINT denom;
				FLOAT diff;
				str = strtok(NULL, " \r\n\t;");
				if (str == NULL){
					printf("please enter a number after the command\n");//print usage
					goto redo;//go back to start
				}
				else{
					fl = strtofl(str);//get number
				}
				str = strtok(NULL, " \r\n\t;");
				if (str == NULL){
					denom = DEF_DENOM;//set to default
				}
				else{
					denom = inttouint(strtoint(str));//get number
				}
				FRACTION frac = fltocfr(fl, denom, &diff);//get fraction
				if (frac.d == 0){//if denominator is 0
					goto redo;//go back to start
				}
				frtostr(val_1, frac);//get fraction
				fltostr(val_2, diff);//get difference
				printf("%s \ndifference ratio of %s\n", val_1, val_2);//print out result
			}

			else if (strcmp(command, "fltofr") == 0){//if converting float to fraction
				FLOAT fl;//values to fill with
				UINT denom;
				FLOAT diff;
				str = strtok(NULL, " \r\n\t;");
				if (str == NULL){
					printf("please enter a number after the command\n");//print usage
					goto redo;//go back to start
				}
				else{
					fl = strtofl(str);//get number
				}
				str = strtok(NULL, " \r\n\t;");
				if (str == NULL){
					denom = DEF_DENOM;//set to default
				}
				else{
					denom = inttouint(strtoint(str));//get number
				}
				FRACTION frac = fltofr(fl, denom, &diff);//get fraction
				if (frac.d == 0){//if denominator is 0
					goto redo;//go back to start
				}
				frtostr(val_1, frac);//get fraction
				fltostr(val_2, diff);//get difference
				if (equalsfl(diff, fltoFl(0))) printf("%s \n", val_1, val_2);//print out result
				else printf("%s \ndifference ratio of %s\n", val_1, val_2);//print out result with difference ratio
			}

			else if (strcmp(command, "frtofl") == 0){//if converting fraction to float
				FRACTION fr;//values to fill with
				FLOAT fl;
				fr = strtofr(strtok(NULL, "\r\n\t;"));//get value
				fl = frtofl(fr);//convert value
				fltostr(val_2, fl);//get string
				printf("%s\n", val_2);//print out result
			}
		}
	}
}

