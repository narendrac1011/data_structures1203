/*
We know that,
A Max Heap is a complete Binary Tree in which the value of each internal node is greater than or equal to their child nodes
For a Node i, the child nodes of i are given by 2*i + 1 and 2*i + 2.
Given a Node j, the parent node would be (j - 1)/2.

*/


#include<stdio.h>
#include<stdlib.h>


//Swap Function
//a[x], a[y] = a[y], a[x]
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


//Generate an Array
int *GenerateArray(int n){
	int * t = malloc(n * sizeof(int) );
	if(t){
		for(int i = 0; i < n; i++){
            t[i] = rand()%150;
        }
	}
	return t;
}


//Print Array
void PrintArray(int *a, int size){

	for(int i = 0; i < size; i++) {
		printf( i?", %d":"%d", a[i]);
	}
	printf(".\n");
}


//Create Max Heap
//We will use J.W.J Williams Algorithm to create the Heap
//We compare each element in the array with its parent
//If it is greater than its parent, we swap them
//This way, we would get a Max Heap
void CreateMaxHeap(int *a, int size){

    //Check for each and every Element in the array
    for (int i = 0; i < size; i++){

        int j = i;

        while(j > 0){

            //For the node j, the parent woukd at the location (j - 1)/2.
            int parent = (j - 1) / 2;

            //If the value of parent node is smaller than the child node, we swap!
            if(a[parent] < a[j]){
                swap(&a[parent] , &a[j]);
            }

            //Break out if there are no swaps.
            else{
                break;
            }

            //After swapping, we set the child as the parent node.
            j = parent;

        }//We keep doing this until, j is equal to the first index, i.e. 0.

    }//We keep repeating this for every element in the Array, until we get a stable Max Heap.
}


//Insert in Max Heap
int *InsertMaxHeap(int *a, int size, int val){
    
    //We Reallocate memory and change the size assigned to size + 1.
    a = realloc(a, (size + 1)*sizeof(int));

    //The Last Element in the array would be assigned the value that is to be Inserted.
    a[size] = val;

    int j = size;

    //We check if the Max heap is stable after the insertion.
    //If not, we take the element to a stable location where the properties of Max Heap won't get effected!
    while(j > 0){

        //For the node j, the parent would be at the location (j - 1)/2.
        int parent = (j - 1)/2;

        //If the value of parent node is smaller than the child node, we swap!      
        if(a[parent] < a[j]){
            swap(&a[parent] , &a[j]);
        }

        //Break out if there are no swaps.
        else{
            break;
        }

        //After swapping, we set the child as the parent node.
        j = parent;

    }//We repeat the same thing for the jth index, i.e. the new parent node

    //Return the new array (Max Heap).
    return a;
}


//Main Function
int main(){

    //Array Generation
    int *array;
    int size = 5;
    array = GenerateArray(size);

    //Print the Unsorted Array
    printf("The Array is: ");
    PrintArray(array, size);

    //Create Max Heap and Print It!
    CreateMaxHeap(array, size);
    printf("The Max Heap is: ");
    PrintArray(array, size);

    //Insertions
    InsertMaxHeap(array, size, 48);

    InsertMaxHeap(array, size + 1, 37);

    InsertMaxHeap(array, size + 2, 54);

    //Printing the Max Heap after Insertions
    printf("The Max Heap after insertion: ");
    PrintArray(array, size + 3);

}