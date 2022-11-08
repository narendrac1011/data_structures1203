/*
We know that,
A Min Heap is a complete Binary Tree in which the value of each internal node is less than or equal to their child nodes
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


//Create Min Heap
//We will use J.W.J Williams Algorithm to create the Heap
//We compare each element in the array with its parent
//If it is smaller than its parent, we swap them
//This way, we would get a Min Heap
void CreateMinHeap(int *a, int size){

    //Check for each and every Element in the Array
    for (int i = 0; i < size; i++){

        int j = i;

        while(j > 0){

            //For the node j, the parent woukd at the location (j - 1)/2.
            int parent = (j - 1) / 2;

            //If the value of parent node is greater than the child node, we swap!
            if(a[parent] > a[j]){
                swap(&a[parent] , &a[j]);
            }

            //Break out if there are no swaps.
            else{
                break;
            }

            //After swapping, we set the child as the parent node.
            j = parent;

        }//We keep doing this until, j is equal to the first index, i.e. 0.

    }//We keep repeating this for every element in the Array, until we get a stable Min Heap.
}


//Delete a Node in Min Heap
int *DeleteMinHeap(int *a, int size, int val){

    //Finding the Element which has to be deleted
    int i = 0;
    while(i < size){

        //If the Element to be deleted is at the i-th index
        if(val == a[i]){

            //We replace the value at ith index with the value of last index in the array
            //This way, we would have 2 values that are similar, i.e. the ith index value and last index value
            a[i] = a[size - 1];

            //So, we reduce the size of the array by 1.
            //Since, we reduced the array size by 1, we would not have the value that was supposed to be deleted in the array
            //Instead, we would have the value of last element at its index.
            size--;

            //We break since we have successfully deleted the value

            break;
        }

        //If a[i] != val, we increase the value of i (move on to the next index).
        i++;
    }

    //Now we have to take the ith index element to a location where the properties of Min Heap won't get effected.
    //Left Child index of Parent 'i' = 2*i + 1.

    //While the left Child index is smaller the size of array, we check for the Stability of the Min Heap
    //If it is stable after the deletion of the element, we print the new array (Min Heap)
    //Else if, it is not stable, we take the element to a stable location, where the properties of Min Heap won't get effected.
    while((2 * i) + 1 < size){

        //child = index of left child
        //child + 1 = index of right child
        //If the value of left child is greater than the right child, then we increment child by 1.
        //If the value of right child is less than the value of left child, then while swapping we would swap parent with the right child
        //We now swap the value of right child with the value of parent node, as per the stability.
        int child = (2 * i) + 1;
        if(child + 1 < size && a[child] > a[child + 1]){
            child = child + 1;
        }
        
        //If the value of a[i] is greater than the value of a[child], we swap!
        //In other words, if the value of parent node is greater than the value of child node, we swap!
        if(a[i] > a[child]){
            swap(&a[i], &a[child]);
        }

        //Break out if there are no swaps.
        else{
            break;
        }

        //After swapping, we set the parent(i) index to the index of child, to further check the stability of the Min Heap.
        i = child;

    }//We repeat the same thing until we get a stable Min Heap.

    //Return the new Array (Min Heap)
    return a;
}


//Main Function
int main(){

    //Array Generation
    int *array;
    int size = 15;
    array = GenerateArray(size);

    //Print the Unsorted Array
    printf("The Array is: ");
    PrintArray(array, size);

    //Create Min Heap and Print It!
    CreateMinHeap(array, size);
    printf("The Min Heap is: ");
    PrintArray(array, size);

    //Deletion
    DeleteMinHeap(array, size, 14);

    //Printing the new Min Heap
    printf("The Min Heap after Deletion: ");
    PrintArray(array, size - 1);
}