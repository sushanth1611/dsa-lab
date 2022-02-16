//14.Implementation of Insertion Sort
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertion_sort(a,n);
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