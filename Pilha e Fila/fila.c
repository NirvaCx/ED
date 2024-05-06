#include <stdio.h>
#include <stdlib.h>

struct Queue{
	int data;
	struct Queue* next;
};

// this implementation of queue uses a single-linking, start-inserted linked list.

void initQueue(struct Queue** newqueue);
void qPush(struct Queue** queuepointer, int data);
int qPop(struct Queue** queuepointer);
// missing queueData because I'm lazy;

int main(){
	// could do a regular pointer and pass its address to the functions but it makes very little difference
	// since C already passes everything by "value" anyway unlike c++
	struct Queue** newq = malloc(sizeof(struct Queue));
	// testing the stuff
	initQueue(newq);
	for(int i = 0; i < 10; i++) qPush(newq, i);
	for(int i = 0; i < 10; i++) printf("%d\n", qPop(newq));
	
	return 0;
}

void initQueue(struct Queue** newqueue){
	*newqueue = NULL;
}

void qPush(struct Queue** queuepointer, int data){
	struct Queue *p1, *p2;
	p1 = malloc(sizeof(struct Queue));
	p1->data = data;
	p1->next = NULL;
	if(*queuepointer == NULL){
		*queuepointer = p1;
	} else {
		// new queue members get pushed to last place
		p2 = *queuepointer;
		while(p2->next != NULL) p2 = p2->next;
		p2->next = p1;
	}
}

int qPop(struct Queue** queuepointer){
	if(*queuepointer == NULL){
		// popping from empty throws exception
		// feel free to implement the isEmpty function yourself
		printf("Can't pop from empty queue\n");
		exit(-1);
	} else {
		// pop simply pops first element in the queue
		struct Queue* p1 = *queuepointer;
		int popdata = p1->data;
		*queuepointer = (*queuepointer)->next;
		free(p1);
		return popdata;
	}
}