#include <stdio.h>
#include <stdlib.h> 
int main(){
    int size;
    int *arr,*arr2;

    do{
        printf("Nhap size: ");
        scanf("%d", &size);
    }while(size < 0 || size >= 100);

    arr = (int *)malloc(size * sizeof(int));
    
    printf("nhap cac phan tu cho mang\n");
    for (int i = 0; i < size; i++) { 
        scanf("%d", &arr[i]);
    }
    arr2 = (int *)malloc(size * sizeof(int));
    int count = 0;
    for(int i = size - 1 ; i >= 0 ; i--){
        arr2[count++] = arr[i];
    }
    for (int i = 0; i < size; i++) { 
        printf("%d ",arr2[i]);
    }
    free(arr);
    return 0;
}