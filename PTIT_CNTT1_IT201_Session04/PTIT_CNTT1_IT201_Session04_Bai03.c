#include <stdio.h>
int main() {
    int n ,arr[n];
    printf("nhap so luong mang: ");
    scanf("%d",&n);
    printf("nhap cac phan tu cho mang\n");
    for(int i = 0 ; i < n ; i++){
        printf("arr[%d]=",i);
        scanf("%d",&arr[i]);
    }
    printf("mang la: \n");
    for(int i = 0 ; i < n ; i++){
        printf("arr[%d]= %d\n",i,arr[i]);
    }
    int min = arr[0];
    int index = 0 ;
    for(int i = 1 ; i < n ; i++){
        if(arr[i]<min){
            min = arr[i];
            index = i;
        }
    }
    printf("%d",index);
    return 0;
}