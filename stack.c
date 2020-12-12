#include<assert.h>
#include "stack.h"
#include <stdint.h>
#include  <string.h>
Stack   stack_new(uint32_t size){
size=(size>0 && size<MAX_DEPTH)? size:MAX_DEPTH;
Stack s1={size,-1,{0}};
return s1;
}


uint8_t   stack_full(const Stack *stk){
assert(stk!=NULL);
return ((stk->top+1)==stk->size);
}

uint8_t    stack_empty(const Stack *stk){
assert(stk !=NULL);
return ((stk->top )== -1); //no element in the stack

}

Stack*  stack_push(Stack *stk,float ele,StackResult *res){
assert(stk!=NULL);
if((stk->top+1)<(stk->size)){
    stk->data[++stk->top]=ele;
    res->status=STACK_OK;
    res->data=ele;
}
else{
    res->status=STACK_FULL;
}
return stk;
}

Stack* stack_pop(Stack *stk,StackResult *res){
assert (stk!=NULL);
if(stk->top!=-1){
    res->data=stk->data[stk->top];
    --stk->top;
    res->status=STACK_OK;
}else{
res->status=STACK_EMPTY;
}
return stk;
}


Stack* stack_peek(Stack *stk,StackResult *res){
assert(stk!=NULL);
if(stk->top!=-1){
    res->data=stk->data[stk->top];
    res->status=STACK_OK;
}else{
res->status=STACK_EMPTY;
}
return stk;

}


//Check balancing of symbols (like ‘{‘, ‘(‘, ‘[‘ ) and their order using stack.
uint8_t isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}


uint8_t areBracketsBalanced(char exp[])
{
    int i = 0;

    // Declare an empty character stack
    Stack s1 = stack_new(20);
    Stack *stack = &s1;
    StackResult res;
    assert (stack_empty(stack));

    // Traverse the given expression to check matching
    // brackets
    while (exp[i])
    {

        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '['){
             stack = stack_push(stack, exp[i],&res);
        }

        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {

        if (stack ->top == -1)
                return 0;

        else {
                stack = stack_pop(stack,&res);
                if (!isMatchingPair(res.data, exp[i]))
                    return 0;
            }
        }
        i++;
        }

    if (stack->top == -1){
         return 1; // balanced
    }
    else{
        return 0; // not balanced
    }

}







