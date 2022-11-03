#include<stdio.h>

//Insertion Sort
void InsertionSort(int a[], int n){

    //For Empty List
    if(!a){
        return;
    }

    for (int i = 1; i < n; i++){
        int x = a[i];
        int j = i - 1;

        while(x < a[j] && j >= 0){
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = x;
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

    //Insertion Sort of the above Array
    InsertionSort(array, n);

    //Print the Sorted Array
    printf("The Sorted Array using Insertion Sort is: ");
    PrintArray(array, n);
}