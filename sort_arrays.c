#include <stdio.h>
#define MAX_SIZE 100

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void main() {
    int n,l,arr1[MAX_SIZE],arr2[MAX_SIZE],outarr[MAX_SIZE];
        printf("Enter the size of the 1st array :\t");
        scanf("%d", &n);
        printf("Enter the Elements of the First Array :");
        for(int i = 0;i<n;i++){
            scanf("%d",&arr1[i]);
        }

        printf("Enter the size of the 2nd array:\t ");
        scanf("%d", &l);
        printf("Enter the Elements of the Second Arra : ");
        for(int k = 0;k<l;k++){
            scanf("%d",&arr2[k]);
        }

        for(int i=0;i<n+l;i++){
            if(i<n){outarr[i]=arr1[i];}
            else{outarr[i]=arr2[i-n];}
        }

        printf("The Merged Array is:{");
        for(int i=0;i<n+l;i++){
                printf("%d ",outarr[i]);
        }printf("}\n");

    sort(outarr,n+l);
    printf("Sorted array in ascending order:{ ");
    
    for (int i = 0; i < n+l; i++) {
        printf("%d ", outarr[i]);
    }
    printf("}\n");
}

