// 13.Implementation of Selection Sort
#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void selection_sort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
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
    selection_sort(a,n);
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