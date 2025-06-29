#include <stdio.h>
#include <stdlib.h> 
int main(){
    int size;
    int *arr;
    do{
        printf("Nhap size: ");
        scanf("%d", &size);
    }while(size < 0 || size >= 100);
    arr = (int *)malloc(size * sizeof(int));
    printf("nhap cac phan tu cho mang\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int n ,count=0;
    printf("nhap so bat ki de ktra: ");
    scanf("%d",&n);
    for(int i = 0 ; i < size ; i++){
        if(n==arr[i]){
           count++;
        }
    }
    printf("%d",count);
    free(arr);
    return 0;
}