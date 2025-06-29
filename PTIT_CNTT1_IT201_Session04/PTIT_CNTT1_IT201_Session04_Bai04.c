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
    int check;
    int index = -1 ;
    printf("nhap mot gia tri bat ki: ");
    scanf("%d",&check);
    for(int i = 0 ; i < n ; i++){
        if(arr[i]==check){
            index = i ;
        }
    }
    if(index){
       printf("%d",index);
    }else{
        printf("khong tim thay phan tu");
    }
    return 0;
}