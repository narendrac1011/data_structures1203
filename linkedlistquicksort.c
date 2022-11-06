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


//Find the Last Element of the Linked List
NodeAddress LastElement(NodeAddress head){

    NodeAddress temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    return temp;
}


//Partition
NodeAddress Partition(NodeAddress start, NodeAddress end){

    //Base Cases
    //If the Linked List is empty, we return NULL
    //If the Linked List has only one element, we return that element
    if(start == NULL || start == end){
        return start;
    }
    
    //We take the last element in the Linked List as the pivot
    int pivot = end->val;

    //We set prev and curr as start 
    NodeAddress prev = start;
    NodeAddress curr = start;


    while(start != end){

        //Till we reach the last element in the Linked list,
        //We place all elements smaller than pivot to the left of it and all greater elements to the right of it!
        //This way we would have all the smaller elements than pivot to the left
        //And all the greater elements to the right
        if(start->val < pivot){
            prev = curr;

            //Swap Values
            int temp = curr->val;
            curr->val = start->val;
            start->val = temp;

            curr = curr->next;        
        }

        //Go to the next element
        start = start->next;

    }//Repeat till we reach the last element of the Linked List

    //We take pivot to the correct location, since it would be at the last after the rearrangement
    //We swap the values of current and pivot (i.e. end).
    int temp = curr->val;
    curr->val = pivot;
    end->val = temp;

    return prev;
}


//Quick Sort
NodeAddress LLQuickSort(NodeAddress start, NodeAddress end){

    //Base Cases
    //If the Linked List is empty, we return NULL!
    //If the Linked List has only one Element, then There is no need to sort!
    if (start == NULL || start == end){
        return start;
    }

    //We take a pivot in the Linked List
    NodeAddress pivot = Partition(start, end);

    //We sort the Linked List from Start to the Pivot using Quick Sort
    LLQuickSort(start, pivot);

    //If the pivot is the start, then we Sort the Linked List from pivot->next to the end
    if (pivot != NULL && pivot == start){
        LLQuickSort(pivot->next, end);
    }

    //Else if, pivot is any other element apart from the start, we Sort the Linked List from pivot->next to the end
    //Since, we have already sorted from start to the pivot, we would get a sorted Linked List by sorting from pivot->next to end.
    else if (pivot != NULL && pivot->next != NULL){
        LLQuickSort(pivot->next, end);
    }
}


//Main
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


    //Printing the Linked List before Sorting
    printf("The Linked List without Sorting: ");
    printLinkedList(head);
    printf("\n");

    //We get the last Element of the Linked List
    NodeAddress tail = LastElement(head);
    
    //Sort the Linked List using Quick Sort and Print It!
    LLQuickSort(head, tail);
    printf("The Linked List after Quick Sort: ");
    printLinkedList(head);

    free(head);

    return 0;
}


//My Scanf command doesn't work. So, I have inputted the values myself.