#include "Appconst.h"
#include <stdint.h>


#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct  _stack_  Stack;
struct  _stack_{
uint32_t  size;
int32_t   top;
float      data[MAX_DEPTH];

};


typedef struct  _stack_result_  StackResult;


struct _stack_result_{
float data;
//char data;
uint8_t status;


};

/*Public interfaces*/

Stack   stack_new(uint32_t size);
uint8_t stack_full(const Stack *stk);
uint8_t stack_empty(const Stack *stk);
Stack*  stack_push(Stack *stk,float ele,StackResult *res);
Stack*  stack_pop(Stack *stk,StackResult *res);
Stack*  stack_peek(Stack *stk,StackResult *res);
int8_t  isMatchingPair(char character1, char character2);
int8_t  areParenthesBalanced(char* exp);
#endif // STACK_H_INCLUDED
