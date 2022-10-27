#include<stdio.h>
#include<stdlib.h>

void display(int arr[], int size){

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

}

void swap(int arr[], int i, int j){

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

int partition(int arr[], int l, int r){

    int pivot = arr[r];
    int i = l - 1;
    int j = l;

    for(j; j < r; j++){

        if (arr[j] < pivot){

            i++;
            swap(arr, i, j);

        }
    }

    swap(arr, i + 1, r);

    return i + 1;

}

void quicksort(int arr[], int l, int r){

    if (l < r){

        int pivotIndex = partition(arr, l, r);
        quicksort(arr, l, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, r);

    }
}

int main(){

    int numbers[6] = {4, 6, 1, 3, 5, 2};

    printf("\nBefore sorting:\n");
    display(numbers, 6);
    
    quicksort(numbers, 0, 5);

    printf("\n\nAfter sorting:\n");
    display(numbers, 6);

    return 0;
}