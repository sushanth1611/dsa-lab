// 15. Implementation of Heap Sort
#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;  
    if (left < n && arr[left] > arr[largest])
      largest = left;  
    if (right < n && arr[right] > arr[largest])
      largest = right;
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  

void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);  
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
}

int main(){
    int n,i;
    printf("Enter the no of elements: ");
    scanf("%d",&n);
    int *a = (int *)malloc(sizeof(int)*(n-1));
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("The array befor sorting is:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    heap_sort(a,n);
    printf("\nThe array after the sort is:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}

/*
Output:
Enter the no of elements: 5
30
10
40
20
50
The array befor sorting is:
30 10 40 20 50 
The array after the sort is:
10 20 30 40 50 
*/