#include <stdio.h>
#include <stdlib.h>

struct Stack{
	int data;
	// the choice of calling the pointers to the next elements
	// pointers to the "previous" elements instead is purely
	// subjective and makes no real difference
	struct Stack *prev;
};

// this implementation of stack uses a single-linking, start-inserted linked list.

void initStack(struct Stack** stackpointer);
void push(struct Stack** stackpointer, int data);
int pop(struct Stack** stackpointer);
int stackData(struct Stack** stackpointer);

int main(){
	// same thing as in the Queue source, I prefer to create an actual pointer to a pointer than to pass
	// the pointer by its address (pass by reference) - personal preference since this code is pretty small
	struct Stack** newStack = malloc(sizeof(struct Stack));
	// testing the functions
	initStack(newStack);
	for(int i = 0; i < 10; i++) push(newStack, i);
	for(int i = 0; i < 10; i++) printf("%d\n", pop(newStack));
	// below will throw an exception before printing hello
	// (trying to pop from an empty stack)
	printf("%d\n", pop(newStack));
	printf("hello");
	return EXIT_SUCCESS;
}

void initStack(struct Stack** stackpointer){
	*stackpointer = NULL;
}

void push(struct Stack** stackpointer, int data){
	struct Stack* p1;
	p1 = malloc(sizeof(struct Stack));
	p1->data = data;
	if(*stackpointer == NULL){
		*stackpointer = p1;
		(*stackpointer)->prev = NULL;
	} else {
		// pushing to stack simply adds an element to its start and pushes
		// the others back
		p1->prev = *stackpointer;
		*stackpointer = p1;
	}
}

int pop(struct Stack** stackpointer){
	if(*stackpointer == NULL){
		// throws an exception and interrupts when trying to free a null pointer
		printf("Can't pop from empty stack\n");
		exit(-1);
	} else {
		// pops the start and moves start to the next
		struct Stack* p1 = *stackpointer;
		int popdata = (*stackpointer)->data;
		*stackpointer = (*stackpointer)->prev;
		free(p1);
		return popdata;
	}
}

int stackData(struct Stack** stackpointer) {
	// gets data from stack without popping it
	if (*stackpointer != NULL) return (*stackpointer)->data; 
	else printf("No data in stack\n"); 
	return 0;
}