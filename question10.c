//10. Implementation of binary search
#include <stdio.h>
#include <stdlib.h>

int binary_search(int* array,int x,int start,int end){
    if(start<=end){
        int mid = (start+end)/2;
        if(array[mid]==x){
            return mid;
        }
        else if(array[mid] > x){
            return binary_search(array,x,start,mid-1);
        }
        else{
            return binary_search(array,x,mid+1,end);
        }
    }
    else{
        return -1;
    }
}

void print_result(int res){
    if(res==-1){
        printf("Not Found.");
    }
    else{
        printf("The element is present at the index: %d",res);
    }
}

int main(){
    int n,x,res;
    printf("Enter the no of elements: ");
    scanf("%d",&n);
    int *a = (int *)malloc(sizeof(int)*(n-1));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    } 
    printf("Enter the element you want to search: ");
    scanf("%d",&x);
    print_result(binary_search(a,x,0,n));
    return 0;
}

/*
Output:
Enter the no of elements: 5
10
20
30
40
50
Enter the element you want to search: 40
The element is present at the index: 3
*/
