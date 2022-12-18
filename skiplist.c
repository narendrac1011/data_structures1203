#include<stdio.h>
#include<stdlib.h>


//Any Node of this type has 3 things - Value of the Node, Next Node and Jump Node (Jump in SkipList)
struct node{
    int val;
    struct node *next;
    struct node *jump;
};

typedef struct node NodeAddress;


//Generating a random array of size n
int *GenerateArray(int n) {
	int *t = malloc(n * sizeof(int));

	for(int i = 0; i < n; i++){
        t[i] = rand() % 1000;
    }

	return t;
}


//Print Array
void PrintArray(int *a, int n) {
	printf("Array = ");
	for(int i = 0; i < n; i++) {
		printf("%d  ", a[i]);
	}
    printf("\n");
}


//Printing the Linked List
void PrintSkipList(NodeAddress *head){

    NodeAddress *temp = head;

    while(temp != NULL){
        printf("%d -> ", temp->val);
        temp = temp->next;
    }

    if(temp == NULL){
        printf("NULL");
    }

    printf("\n");
}


//Printing the Linked List of only j-th (4th) Nodes
void PrintSkipList2(NodeAddress *head){

    NodeAddress *temp = head;

    while(temp != NULL){
        if(temp->jump != NULL){
        printf("%d -> ", temp->val);
        }
        temp = temp->next;
    }
    
    if(temp == NULL){
        printf("NULL");
    }

    printf("\n");
}


//Free Linked List
void FreeLinkedList(NodeAddress *head) {
	NodeAddress *prev;
	while(head != NULL) {
		prev = head;
		head = head->next;
		free(prev);
	}
}


//Skip List
NodeAddress *SkipList(int *a, int size){

    NodeAddress *head = NULL;
    NodeAddress *temp = NULL;

    //Special Case for Head
    if(size > 0){
        head = malloc(sizeof(struct node));
        head->val = a[0];
        head->next = NULL;
        head->jump = NULL;
        temp = head;
    }

    //Assign other values in the array to the list
    for(int i = 1; i < size; i++){
        temp->next = malloc(sizeof(struct node));
        temp = temp->next;
        temp->val = a[i];
        temp->next = NULL;
        temp->jump = NULL;
    }

    //Counter for the Jump and the distance between Jumps
    int num = 0;
    int lift = 4;

    //Calculating the Nodes values for the Skip List
    for(temp = head; temp->next != NULL; temp = temp->next){

        if(num % lift == 0){
            temp->jump = temp;
        }
    
        num++;
    }

    return head;
}


int main(){

    //Generating Random array and Printing it!
    int size = 15;
    int *array = GenerateArray(size);
    PrintArray(array, size);


    //Skiplist function - One Linked List going through every node and one going through all j-th (4th) nodes!
    NodeAddress *head = SkipList(array, size);

    printf("The Linked List: ");
    PrintSkipList(head);

    printf("The Linked List with Jumps: ");
    PrintSkipList2(head);

    FreeLinkedList(head);
    return 0;
}