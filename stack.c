#include<stdio.h>
#include<stdlib.h>


//Stack of Positive Numbers
struct stackType {
	int *val;
	int size;
	int top;
};


typedef struct stackType * StackAddress;


//Initialize Stack
StackAddress InitStack() {
	StackAddress stack = malloc( sizeof(struct stackType) );
	stack->top  = -1;
	stack->size = 100;
	stack->val = malloc( stack->size * sizeof(int) );
	return stack;
}


//Insert in a Stack
int InsertStack(StackAddress stack, int val){

    //Stack is Full
	if( stack->top == stack->size-1 ){
        return -1;
    } 

	if( val < 0 ){
        return -2;
    }

	stack->val[ ++stack->top ] = val;
	return val;
}


//Extract in a Stack
int ExtractStack(StackAddress stack){

    //Stack is empty
	if( stack->top < 0 ){ 
        return -1;
    }

	return stack->val[ stack->top-- ];
}


//Free Stack
void FreeStack(StackAddress stack){
	free(stack->val);
	free(stack);
}


//Main Function
int main(){

	printf("Stack: ");
	StackAddress stack = InitStack();

	InsertStack(stack, 10);
	InsertStack(stack, 20);
	InsertStack(stack, 30);
	InsertStack(stack, 555);

	printf("%d ", ExtractStack(stack));
	printf("%d ", ExtractStack(stack));
	printf("%d ", ExtractStack(stack));
	printf("%d ", ExtractStack(stack));

	FreeStack(stack);
    return 0;
}