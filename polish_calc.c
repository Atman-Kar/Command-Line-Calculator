#include<stdio.h>
#include<string.h>
#include "calc.h"

#define MAXSIZE 16       
double stack[MAXSIZE];     
int top = -1;            

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() {
   /* returns top of stack */
   return stack[top];
}

double pop() {
   double data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
      return -1000000;
   }

}

void push(double data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

double solve(char * pol_expr){
	//printf("%s\n", pol_expr);
	int i;
	double j;
	double val = 0;
	int oper; /* If the previous token was an operator or not */
	for(i = 0 ; i < strlen(pol_expr) ; i++){

		switch(pol_expr[i]){

			case ' ':
				if(!oper){
					push(val);
					val = 0;
				}
				break;

			case '+':
				push(pop() + pop());
				oper = 1;
				break;

			case '-':
				j = pop();
				push(pop() - j);
				oper = 1;
				break;

			case '/':
				j = pop();
				push(pop() / j);
				oper = 1;
				break;

			case '*':
				push(pop() * pop());
				oper = 1;
				break;

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
				oper = 0;
				val = (val * 10 + (pol_expr[i] - '0'));
				break;

			default:
				printf("ERROR\n");
				//exit(1);

		}
	}

	return pop();
}