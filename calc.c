/*

Goal: Building a command line calculator.

Example: 
	I/P = 5 / 2 + 3 - 4 x 2 =

	O/P = -2.5

Requirements:
	
	1) Accepts a maximum of 80 characters input.

	2) Every valid expression entered, must end with an '=' sign to be computed.

	3) The only valid operations are '+' , '-' , '/' and 'x'.

	4) The calculator must follow BODMAS rule to return the correct answer.

	5) For wrong inputs, an error must be thrown, along with a guide to help the user rectify the error.


Test Cases:
	
	Functional Test Cases:

		1) '5 / 2 + 3 - 4 x 2 ='.

		2) Valid expression that is 80 char long.

		3) Check for BODMAS:

			a) '5 / 2 + 3 - 4 x 2 ='
			b) '3 - 4 x 2 + 5 / 2 ='

			a) and b) must yield the same result.

		4) '65111.9 / 5.3 ='.

	Negative Test Cases:

		1) '-5 + 10 =' ,  expression starting off with operation.

		2) '/5 + 10 =' and 'x5 + 10 =' must throw an error.

		3) Enter an expression > 80 chars.

		4) No '=' to terminate the expression.

		5) Unknown operation used.

		6) Division by zero exception.

		7) Only '='.

		8) Repeated operands: '5//2 ='.

Design:

	1) I/P: Terminal, input string, scan input.

	2) Pre-validation

	3) Tokenize 
	
	4) Linked-List. Node ---> | value | operation | next |

	5) Walk n Reduce ---> BODMAS

	6) O/P
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<ctype.h>
#include "calc.h"

/* Remove spaces from the input string */

void RemoveSpaces(char* source){
  char* i = source;
  char* j = source;
  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
      i++;
  }
  *i = 0;
}

/* Pre-validating input before further processing */

int pre_validating_input_string(char * input , int flag){

	int length = strlen(input);
	int equal_to_count = 0;


	int left = 0; //Count of left paranthesis
	int right = 0; //Count of right paranthesis

	 if(length > 80){
	 	printf("ERROR: Please enter expression lesser than 80 characters\n");
	 	return 1;
	 }

	 if(length == 0){
	 	printf("ERROR: Please enter a string\n");
	 	return 1;
	 }

	 if(flag){
	 	if(*(input + length - 2) != '='){
		 	printf("ERROR: Expression must end with an '=' sign.\n");
		 	return 1;
		 }
	 }
		 

	 if(*input == '/' | *input == '*'){
	 	printf("ERROR: Invalid expression. Cannot start with '/' or '*'\n");
	 	return 1;
	 }

	 for(int i = 0 ; i < length - 1 ; i++){
	 	if(*(input + i) == '=') equal_to_count++;

	 	if(*(input + i) == '(') left++;

	 	if(*(input + i) == ')') right++;

	 	if(equal_to_count > flag){
	 		printf("ERROR: Cannot have more than one equal to sign.\n");
	 		return 1;
	 	}

	 	if(*(input + i) == '.'){
	 		continue;
	 	}

	 	if((i != 0) && ((*(input + i) == '+') | (*(input + i) == '-') \
	 		| (*(input + i) == '/') | (*(input + i) == '*'))){

	 		if(((*(input + i - 1) == '+') | (*(input + i - 1) == '-')\
	 			| (*(input + i - 1) == '/') | (*(input + i - 1) == '*'))){

	 			printf("ERROR: Repeated operators\n");
	 			return 1;
	 		}
	 	}

	 	if(!isdigit(*(input + i)) && (*(input + i) != '+') && (*(input + i) != '-') \
	 		&& (*(input + i) != '/') && (*(input + i) != '*') && (*(input + i) != '=') \
	 		&& (*(input + i) != '(') && (*(input + i) != ')')){
	 		
	 		printf("ERROR: Unknown operation used.\n");
	 		return 1;
	 	}
	 }


	 if(left != right){
	 		printf("ERROR: Unbalanced parantheses\n");
	 		return 1;
	 }

	 return 0;
}


/* Case where string starts with +/- */
int starting_operator_correction(char * input){
	if(*input == '-' | *input == '+'){
			return 1;
	}
	return 0;
}

/* prepend a string to another */
void prepend_string(char* s, const char* t)
{
    size_t len = strlen(t);
    size_t i;

    memmove(s + len, s, strlen(s) + 1);

    for (i = 0; i < len; ++i)
    {
        s[i] = t[i];
    }
}