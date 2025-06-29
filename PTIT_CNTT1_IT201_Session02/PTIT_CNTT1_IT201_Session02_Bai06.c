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
    int pos,val;
	printf("nhap gia tri them: ");
	scanf("%d",&val);
	printf("nhap vi tri muon them: ");
	scanf("%d",&pos);
	if(pos<0||pos>n){
		printf("vi tri khong hop le\n");
	}else{
		for(int i = n ; i >= pos ; i--){
            arr[i]=arr[i-1];
        }
        arr[pos]=val;
        n++;

	    printf("mang vua thay doi la: \n");
		for(int i=0;i<n;i++){
			printf("arr[%d]=%d\n",i,arr[i]);
		}
	}
    free(arr);
	return 0; 
}



