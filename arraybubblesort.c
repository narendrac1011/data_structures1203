#include<stdio.h>
#include<stdlib.h>


//Bubble Sort of Array
void BubbleSort(int *a, int size){

    int sorted, i, t, swap;

    	for(sorted = 0; sorted < size; sorted++) {

		    swap = 0;
		    for(i = 0; i < size-1-sorted; i++){

                //If a[i] is greater than a[i+1], we swap both the values
                //Once we are done with this for loop, we have the largest element at the last
                //So, we now do the same thing from 0 to n-2, i.e. n-1-done
                //This would eventually give the sorted array.

			    if( a[i] > a[i+1] ){
				    t = a[i];
				    a[i] = a[i+1];
				    a[i+1] = t;
				    swap = 1;
		    	}
		    }

		    if(swap == 0){
			    break;
            }
        }
}


//Print Function - Prints the Array
void PrintArray(int a[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

//Main Function
int main(){

    //Array
    int array[] = {11, 23, 1, 59, 37, 10, 16, 28, 98, 84};

    //Size of Array
    int n = sizeof(array) / sizeof(array[0]);

    //Print the Unsorted Array
    printf("The Unsorted Array is: ");
    PrintArray(array, n);

    //Selection Sort of the above Array
    BubbleSort(array, n);

    //Print the Sorted Array
    printf("The Sorted Array using Bubble Sort is: ");
    PrintArray(array, n);
}