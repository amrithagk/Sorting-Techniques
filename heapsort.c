#include<stdio.h>
#include<stdlib.h>

void heapSort(int arr[], int n)
{
    // Step 1: Heap construction
    int k, j, temp, heap;

    // n/2 considering that the array elements are present from index 1 to n
    for (int i = n/2; i >= 1; i--)
    {
        k = i;
        temp = arr[i];
        heap = 0;

        while (!heap && 2*k <= n)
        {
            j = 2 * k;
            if (j+1 <= n && arr[j] < arr[j+1])
            {
                j = j + 1;
            }
            
            if (arr[k] > arr[j])
                heap = 1;
            else
            {
                arr[k] = arr[j];
                arr[j] = temp;
            }
            k = j;
        }
    }

    // Step 2: Apply n-1 deletions on the constructed heap
    for (int i = n; i > 1; i--)
    {
        //swap last and first element
        temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;

        //heapify
        temp = arr[1];
        k = 1;
        heap = 0;

        while (!heap && 2*k <= i - 1)
        {
            j = 2 * k;
            if ( j + 1 <= (i - 1) && arr[j] < arr[j+1] )
                j = j + 1;
            
            if (arr[k] > arr[j])
                heap = 1;
            else
            {
                arr[k] = arr[j];
                arr[j] = temp;
            }
            k = j;
        }
    }
    
}

void display(int arr[], int n)
{
    printf("\n\nThe elements in sorted order:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(){

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    //Input the array elements
    int *arr = (int*)malloc(sizeof(int) * (n+1));
    printf("Enter the elements of the array: ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    //Sort
    heapSort(arr, n);

    //Display
    display(arr, n);

    return 0;
}