#include<stdio.h>
#include<stdlib.h>


//Creating node with 2 variables - Val and Next
struct node{
    int val;
    struct node *next;
};


typedef struct node *NodeAddress;


//Printing the Linked List
void printLinkedList(NodeAddress temp){
    while(temp != NULL){
        printf("%d -> ", temp->val);
        temp = temp->next;
    }

        if(temp == NULL){
        printf("NULL");
    }
}


//Bubble Sort of Linked Lists
NodeAddress LLBubbleSort(NodeAddress head) {
	NodeAddress current, lastDone;
	int t;

	for(lastDone = NULL; lastDone != head; lastDone = current) {

		for(current = head; current->next != lastDone; current = current->next) {

            //If the value at current is greater than the value at current->next, we swap their values
			if( current->val > current->next->val ) {
				t = current->val;
				current->val = current->next->val;
				current->next->val = t;
			}
		} 
	}

	return head;
}


//The Main Function
int main(){

    //Initially, the Values of all the Elements in the Linked List is set to NULL.
    NodeAddress head = NULL;
    NodeAddress second = NULL;
    NodeAddress third = NULL;
    NodeAddress fourth = NULL;
    NodeAddress fifth = NULL;
    NodeAddress sixth = NULL;

    //We allocate memory to the every Element in the Linked List.
    head = (NodeAddress)malloc(sizeof(NodeAddress));
    second = (NodeAddress)malloc(sizeof(NodeAddress));
    third = (NodeAddress)malloc(sizeof(NodeAddress));
    fourth = (NodeAddress)malloc(sizeof(NodeAddress));
    fifth = (NodeAddress)malloc(sizeof(NodeAddress));
    sixth = (NodeAddress)malloc(sizeof(NodeAddress));

    //We enter the values from each address and we go to the next address one after the other
    //Values of different nodes and the sequence of linked list:
    head->val = 19;
    head->next = second;

    second->val = 101;
    second->next = third;

    third->val = 22;
    third->next = fourth;

    fourth->val = 3;
    fourth->next = fifth;

    fifth->val = 48;
    fifth->next = sixth;

    sixth->val = 59;
    sixth->next = NULL;

    //Printing the Unsorted Linked List
    printf("The Linked List without Sorting: ");
    printLinkedList(head);

    //Printing the Sorted List using the LLBubbleSort Function
    printf("\n");
    head = LLBubbleSort(head);
    printf("The Sorted Linked List using Bubble Sort: ");
    printLinkedList(head);

    free(head);

    return 0;
}