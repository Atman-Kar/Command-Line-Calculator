#ifndef CALC_H_
#define CALC_H_

void RemoveSpaces(char *);

int pre_validating_input_string(char * , int);

int  starting_operator_correction(char *);

void prepend_string(char*, const char*);

void reverse_polish(char* , char*);

double solve(char * pol_expr);

#endif