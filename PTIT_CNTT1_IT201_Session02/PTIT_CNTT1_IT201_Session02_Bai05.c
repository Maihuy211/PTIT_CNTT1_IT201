#include <stdio.h>
#include <stdlib.h> 
int main() {
    int n;
    int *arr;
    do{
       printf("Nhap n: ");
       scanf("%d", &n);
    }while(n < 0 || n >= 100);
    arr = (int *)malloc(n * sizeof(int));
    printf("nhap cac phan tu cho mang\n");

    for (int i = 0; i < n; i++) {
        printf("arr[%d]= ",i);
        scanf("%d", &arr[i]);
    }
    int pos;
	printf("nhap vi tri muon xoa: ");
	scanf("%d",&pos);
	if(pos<0||pos>n){
		printf("vi tri khong hop le\n");
	}else{
		for(int i = pos ; i < n - 1 ; i++){
            arr[i]=arr[i+1];
        }
        n--;
        printf("mang vua thay doi la: \n");
        for(int i = 0 ; i < n ; i++){
            printf("arr[%d]=%d\n",i,arr[i]);
        }
	}
    free(arr);
	return 0; 
}

