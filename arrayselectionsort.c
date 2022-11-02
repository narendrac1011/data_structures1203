#include<stdio.h>

//Swap Function
//a[x], a[y] = a[y], a[x]
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//Selection Sort
void SelectionSort(int a[], int n){
    for (int i = 0; i < n - 1; i++){
        int p = i;

        for (int j = i + 1; j < n; j++){
            if (a[j] < a[p]){
                p = j;
            }    
        }

        swap(&a[p], &a[i]);
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
    SelectionSort(array, n);

    //Print the Sorted Array
    printf("The Sorted Array using Selection Sort is: ");
    PrintArray(array, n);
}