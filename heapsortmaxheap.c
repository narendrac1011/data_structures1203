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


//The Heapify code
void heapify(int *a, int size, int i){

    //The Parent node and its 2 Child Nodes
    int parent = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    //If the Value of Left Child is greater than the Value of Parent, then the new Parent = Left Child
    if(left < size && a[left] > a[parent]){
        parent = left;
    }

    //If the Value of Right Child is greater than the value of Parent, then the new Parent = Right Child
    if(right < size && a[right] > a[parent]){
        parent = right;
    }

    //If the Parent has changed, then we swap parent with the Child
    //Then We Heapify Again, until we get a stable Max Heap
    if (parent != i){
        swap(&a[i], &a[parent]);
        heapify(a, size, parent);
    }
}

//Heap Sort
void HeapSort(int *a, int size){

    //We Heapify for i = size/2 - 1 
    //Subtract the value of i and Heapify
    //We repeat this unitl we reach the parent node
    for(int i = (size / 2) - 1; i >= 0; i--){
        heapify(a, size, i);
    }

    //We the do Swaps and Heapify the Entire Array/Max Heap
    for(int i = size - 1; i >= 0; i--){

        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}


//Main Function
int main(){

    //Array
    int array[] = {11, 23, 1, 59, 37, 10, 16, 28, 98, 84};

    //Size of Array
    int size = sizeof(array) / sizeof(array[0]);

    //Print the Unsorted Array
    printf("The Array is: ");
    PrintArray(array, size);

    //Create Max Heap and Print It!
    CreateMaxHeap(array, size);
    printf("The Max Heap is: ");
    PrintArray(array, size);

    //Heap Sort
    HeapSort(array, size);
    printf("The Sorted Array using Heap Sort: ");
    PrintArray(array, size);
}