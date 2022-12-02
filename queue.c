#include<stdio.h>
#include<stdlib.h>


//Queue
struct queueType {
	int *val;
	int start;
	int size;
	int n;
    //n = Number of elements in the Queue.
};


typedef struct queueType * QueueAddress;


//Initialize Queue
QueueAddress InitQueue() {
	QueueAddress queue = malloc( sizeof(struct queueType) );
	queue->n = 0;
	queue->start = 0;
	queue->size = 100;
	queue->val = malloc( queue->size * sizeof(int) );
	return queue;
}


//Insert in a Queue
int InsertQueue(QueueAddress queue, int val) {
	if(queue->n == queue->size){
        return -1;
    }

	if(val < 0){
        return -2;
    }

	queue->val[ (queue->start + queue->n++) ] =  val;
	return val;
}


//Extract from a Queue
int ExtractQueue(QueueAddress queue) {
	if(queue->n == 0){
        return -1;
    }

	queue->n--;
	return queue->val[ queue->start++ ];
}


//Free Queue
void FreeQueue(QueueAddress queue) {
	free(queue);
}


//Main Function
int main(){
    printf("Queue: ");
	QueueAddress queue = InitQueue();

	InsertQueue(queue, 10);
	InsertQueue(queue, 20);
	InsertQueue(queue, 30);
	InsertQueue(queue, 555);

	printf("%d ", ExtractQueue(queue));
	printf("%d ", ExtractQueue(queue));
	printf("%d ", ExtractQueue(queue));
	printf("%d ", ExtractQueue(queue));
	printf("%d ", ExtractQueue(queue));

	FreeQueue(queue);
    return 0;
}