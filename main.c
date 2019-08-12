/* main file */


/* This us a command line editor. */

/*

To run the program, go to your terminal and type in: gcc calc.c main.c sy.c polish_calc.c -o calc 

Then, once it's compiled, type: ./calc

You can then enter any expression that contains values and operations(only +,-,/,*)

*/

#include<stdio.h>
#include "calc.h"

int main(int argc, char const *argv[]){
	char * input = (char *)malloc(85 * sizeof(char));
	int exit_flag;

	char output[256];

	FILE *fp = argc > 1 ? fopen (argv[1], "r") : stdin;

	if (!fp) {  /* validate file open for reading */
        fprintf (stderr, "error: file open failed '%s'.\n", argv[1]);
        return -1;
    }

    if(fp == stdin){
    	fgets(input , 80 , stdin);
    	RemoveSpaces(input); /* strip spaces from the input */
		exit_flag = pre_validating_input_string(input , 1);  /* check for any errors in input. */

		if(exit_flag){
			free(input);
			if(fp != stdin) fclose(fp);
			return -2;
		}

		if(starting_operator_correction(input)) prepend_string(input , "0");

		reverse_polish(input , output);
		printf("%lf\n", solve(output));

    }else{

    	/* Edit code here for file input automated test cases */
    	while(fgets(input, 80, fp)) {

    		RemoveSpaces(input); /* strip spaces from the input */
			exit_flag = pre_validating_input_string(input , 1);  /* check for any errors in input. */

			if(exit_flag){
				printf("Invalid input case.\n");
			}

			if(starting_operator_correction(input)) prepend_string(input , "0");

			reverse_polish(input , output);

			printf("%lf\n", solve(output));
   
		}

    }

	free(input);
	if(fp != stdin) fclose(fp);
	return 0;
}