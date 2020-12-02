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
int8_t  isMatchingPair(char character1, char character2)
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


int8_t areParenthesBalanced(char* exp){
//int n=strlen(st);
Stack s1=stack_new(20);
Stack *stk=&s1;
StackResult res;
int i;

for (i=0;exp[i];++i){
      if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
           stk=stack_push(stk,exp[i],&res);

      else if(exp[i]=='}' || exp[i]==')'  ||  exp[i]==']')
      {
          stk=stack_pop(stk,&res);
          if((stk==NULL) || !isMatchingPair(res.data,exp[i])){
             return 0;
             }
      }



}
if(stk==NULL){
  return 1;
}
else{

  return 0;
}

}

