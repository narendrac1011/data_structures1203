#include<stdio.h>
#include<stdlib.h>

//Anything of the type struct node is allocated in the Memory.
struct node {
    int val;            //val = Value
    struct node *next;      //Next = The next element in the Linked List
};

void CreateList(struct node *Address){
    struct node *t;
    printf("The Data in the Linked List: ");
    for (t = Address; t != NULL; t = t->next)           //For Loop to print and go to the next element in the Linked List
    {
        printf("%d, ", t->val);                 //Prints the Linked List.
    }
}

void CreateChunkList(struct node *Address){
    struct node *t;
    printf("\nThe Data in the Chunk-wise Reverse Linked List: ");
    for (t = Address; t != NULL; t = t->next)           
    {
        printf("%d, ", t->val);                 //Prints the Chunk-wise Reversed Linked List.
    }
}

//Reverses only the 'k' chunk in the Linked List.
struct node *chunkreverse(struct node **current, int k){
    struct node *prev, *next;
    prev = NULL;
    int count = 0;

    while (*current && count++ < k){
        next = (*current)->next;
        (*current)->next = prev;
        prev = *current;
        *current = next;
    }
    return prev;
}

//Reverse every 'k' chunk in the Linked List. In other words, for every k elements, we reverse the chunk.
struct node *ReverseKChunk(struct node *head, int k){
    if (head == NULL){
        return NULL;
    }

    struct node *current, *prev;

    current = head;
    prev = chunkreverse(&current, k);
    head->next = ReverseKChunk(current, k);
    return prev;
}


int main(){

    //Initially, the Values of all the Elements in the Linked List is set to NULL.
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    struct node *fourth = NULL;
    struct node *fifth = NULL;

    //We allocate memory to the every Element in the Linked List.
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

    //We Enter values for each Address and we go to the next address one after the other.
    head->val = 94;
    head->next = second;
    second->val = 127;
    second->next = third;
    third->val = 264;
    third->next = fourth;
    fourth->val = 425;
    fourth->next = fifth;
    fifth->val = 679;
    fifth->next = NULL;        //Once we reach the last element, we have no next Address. So, we give it the value, NULL.

    CreateList(head);         //Create the Linked List, starting with the first Address.

    head = ReverseKChunk(head, 2);
    CreateChunkList(head);

    return 0;
}