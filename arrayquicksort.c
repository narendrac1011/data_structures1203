#include<stdio.h>

//Swap Function
//a[x], a[y] = a[y], a[x]
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//Partition for Quick Sort
int Partition(int a[], int start, int end){

    //Set i = start
    int i = start;

    //We set pivot as the last element in the array
    int pivot = a[end];

    //For loop
    for (int j = start; j < end; j++){
        if (a[j] < pivot){
            swap(&a[i], &a[j]);
            i++;
        }
    }
    
    swap(&a[i], &a[end]);
    return (i);
}

//Quick Sort
void QuickSort(int a[], int start, int end){
    if (!a || start >= end){
        return;
    }

    if (start < end){
        int p = Partition(a, start, end);

        //Sort the part which is lesser than the pivot
        QuickSort(a, start, p - 1);

        //Sort the part which is greater than the pivot
        QuickSort(a, p + 1, end);
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

    //Quick Sort of the above Array
    QuickSort(array, 0, n - 1);

    //Print the Sorted Array
    printf("The Sorted Array using Quick Sort is: ");
    PrintArray(array, n);
}