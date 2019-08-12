/*
 * Program for the Shunting-Yard Algorithm
 *
*/
#include <stdio.h>
#include<string.h>
#include "calc.h"
#define MAXSIZE 100
 
struct stack{
    char stk[MAXSIZE];
    int top;
};

typedef struct stack STACK;

STACK s = {.top = -1};

/*
 * Order of precedence of operators:
 * '/'
 * '*'
 * '+' & '-'
*/

void push_s(char);
char  pop_s(void);
int precedence(char);
 
void reverse_polish(char * input , char * output){
	int j = 0; /* Output Queue index */
	int i;
	char discard;
	for(i = 0 ; i < strlen(input) - 1 ; i++){
		switch(input[i]){
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				output[j++] = input[i];
				break;

			
			case '+':
			case '-':
			case '*':
			case '/':
				output[j++] = ' ';
				while((precedence(s.stk[s.top]) >= precedence(input[i]))\
					    && (s.stk[s.top] != '(')\
					    && (s.top != -1))
				{
					output[j++] = pop_s();
					output[j++] = ' ';
				}
				push_s(input[i]);
				break;

			case '(':
				push_s(input[i]);
				break;


			case ')':
				//output[j++] = ' ';
				while(s.stk[s.top] != '('){
					output[j++] = ' ';
					output[j++] = pop_s();	
				}
				if(s.stk[s.top] == '('){
					discard = pop_s();
				}

		}
	}

	while(s.top != -1){
		output[j++] = ' ';
		output[j++] = pop_s();
	}
}

/* Returns the precedence of the operators */
int precedence(char c){
	int prec;
	switch(c){
		case '+':
		case '-':
			prec = 1;
			break;

		case '*':
			prec = 2;
			break;

		case '/':
			prec = 3;
			break;
	}

	return prec;
}

/*  Function to add an element to the stack */
void push_s (char c){
    if (s.top == (MAXSIZE - 1)){
        printf ("Stack is Full\n");
        return;
    }
    else{
        s.top = s.top + 1;
        s.stk[s.top] = c;
    }
    return;
}
/*  Function to delete and return an element from the stack */
char pop_s (){
    char num;
    if (s.top == - 1){
        printf ("Stack is Empty\n");
        return (s.top);
    }
    else{
        num = s.stk[s.top];
        s.top = s.top - 1;
    }
    return(num);
}