import java.util.*;

public class Mergesort{

    public static void merge(int l, int r, int mid, int[] arr){

        int[] leftArr = new int[mid-l+1];
        int[] rightArr = new int[r-mid];

        int i;
        for (i = 0; i < mid-l+1; i++)
        {
            leftArr[i] = arr[l+i];
        }

        for (i = 0; i < r-mid; i++)
        {
            rightArr[i] = arr[mid+1+i];
        }

        
        i = 0;
        int j = 0, k = l;
        int leftLen = leftArr.length, rightLen = rightArr.length;
        //int leftLen = mid-l+1, rightLen = r-mid;

        while (i < leftLen && j < rightLen) {
            if (leftArr[i] < rightArr[j])
            {
                arr[k++] = leftArr[i++];
            }
            else {
                arr[k++] = rightArr[j++];
            }
        }

        
        while(i < leftLen){
            arr[k++] = leftArr[i++];
        }

        while(j < rightLen){
            arr[k++] = leftArr[j++];
        }
    }

    public static void mergesort(int l, int r, int[] arr){

        if (l >= r) return;
        int mid = (r+l)/2;
        mergesort(l, mid, arr);
        mergesort(mid+1, r, arr);
        merge(l, r, mid, arr);
    }
    public static void main(String[] args){
        System.out.println("Merge Sort");
        int [] arr = new int[]{9,8,7,6,5,4,3,2,1};
        mergesort(0, arr.length-1, arr);
        System.out.println("Sorted Array: "+Arrays.toString(arr)); //print the sorted array
    }
}