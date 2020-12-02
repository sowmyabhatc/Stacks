#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "stack.h"

void test_empty_stack(){
Stack s1=stack_new(20);
Stack *stk=&s1;
assert(stack_empty(stk)==1);
}

void test_full_stack(){
Stack s1=stack_new(2);
Stack *stk=&s1;
StackResult res;
stk=stack_push(stk,10,&res);
assert(res.status==STACK_OK);
stk=stack_push(stk,20,&res);
assert(res.status==STACK_OK);
stk=stack_push(stk,30,&res);
assert(res.status==STACK_FULL);
assert(stack_full(stk)==1);

}

void test_stack(){
Stack s1=stack_new(5);
Stack *stk=&s1;
StackResult res;
stk=stack_pop(stk,&res);
assert(res.status==STACK_EMPTY);


stk=stack_push(stk,10,&res);
stk=stack_push(stk,20,&res);
stk=stack_peek(stk,&res);
assert(res.status==STACK_OK && res.data==20);

stk=stack_pop(stk,&res);
assert(res.status==STACK_OK && res.data==20);
stk=stack_peek(stk,&res);
assert(res.status==STACK_OK && res.data==10);

stk=stack_pop(stk,&res);
assert(stack_empty(stk)==1);
}


//Evaluate postfix expression using stack. Example: postfix fix expression is 6 5 2 3 + 8 * + 3 + *
//Hint: When number is seen, it is pushed onto the stack;
//when an operator is seen, the operator is applied to the two numbers that are popped from the stack, and the result is pushed onto the stack.
void test_post_fix(char* exp){
Stack s1=stack_new(20);
Stack *stk=&s1;
StackResult res;

//int n=("%d",exp[0]-'0');
for (int i=0;exp[i];++i){
    if(exp[i]-'0'>=0)
        stk=stack_push(stk,exp[i]-'0',&res);
    else{
        int val1,val2;
        stk=stack_pop(stk,&res);
        val1=res.data;
        stk=stack_pop(stk,&res);
        val2=res.data;

    switch(exp[i]){
    case '+':
    stk=stack_push(stk,val1+val2,&res);
    break;
    case '-':
    stk=stack_push(stk,val1-val2,&res);
    break;
    case '*':
    stk=stack_push(stk,val1*val2,&res);
    break;
    case '/':
    stk=stack_push(stk,val1/val2,&res);
    break;

    }
}
}
stk=stack_pop(stk,&res);
//printf("%f",res.data);
assert(res.status==STACK_OK  && res.data==288);
}

/*void test_balance(){


assert(areParenthesBalanced(exp)==1);
}*/


int main()

{
    //test_empty_stack();
    //test_full_stack();
    //test_stack();
    //char exp[]="6523+8*+3+*";
    //test_post_fix(exp);
    char exp[]="{()}";
    assert(areParenthesBalanced(exp)==1);
    return 0;
}
