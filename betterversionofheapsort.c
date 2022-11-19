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

//Heap Sort
void HeapSort(int *a, int size){

    //We go through all the elements in the Max Heap
    //We start from the last element in the Max Heap and go upto the Parent root node/element.
    for(int i = size - 1; i > 0; i--){

        //We swap the last and the First element in the Max Heap
        swap(&a[0], &a[i]);

        //We create a New Max Heap of size - 1.
        //We would now have a Max Heap of size - 1 with the largest element at the end of the array
        CreateMaxHeap(a, i);
    }
    //If we keep repeating these till we reach the parent element, we would eventually get a Sorted Array.
    //This is known as the Heap Sort!
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