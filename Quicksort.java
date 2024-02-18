import java.util.*;

public class Quicksort {
    
    private static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    private static int partition(int[] arr, int l, int r){
        int pivot = arr[r];
        int i = l-1;
        int j;
        for (j = l; j <= r; j++){
            if (arr[j] < pivot){
                i++;
                swap(arr, i, j);
            }
        }
        i++;
        swap(arr, i, r);
        return i;
    }

    private static int[] quicksort(int[] arr, int l, int h){
        if (l > h) return arr;
        int piv = partition(arr, l, h);
        quicksort(arr, l, piv-1);
        quicksort(arr, piv+1, h);
        return arr;
    }

    public static void main(String[] args) {
        System.out.println("QuickSort");
        int[] arr = new int[]{9,3, 8, 2, 5, 1, 7, 4};
        arr = quicksort(arr, 0, arr.length-1);
        System.out.print("Sorted array: "+Arrays.toString(arr));
    }
}