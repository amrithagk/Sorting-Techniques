#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[l + i];    //copy 1st half of a to L

    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];    //copy 2nd half of a to R

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    //copy any remaining elements in either half into a

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    } 
}

void mergeSort(int a[], int l, int r)
{

    int mid = ( l + r ) / 2;

    if(l < r)
    {

        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);

    }

    merge(a, l, mid, r);

}

int main(){

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]); 
    }

    printf("Before sorting\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    mergeSort(a, 0, n-1);

    printf("\nAfter sorting\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}