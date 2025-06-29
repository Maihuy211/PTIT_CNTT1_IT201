#include <stdio.h>
#include <stdlib.h> 
void totalMain(int arr[100][100], int n){
    int sum=0;
    for (int i = 0 ; i < n ; i++){
        sum+=arr[i][i]; 
    }
    printf("tong duong cheo chinh = %d\n",sum);
}
void totalSubdiagonal(int arr[100][100], int n){
    int sum=0;
    for (int i = 0 ; i < n ; i++){
        sum+=arr[i][n-i-1]; 
    }
    printf("tong duong cheo phu = %d\n",sum);
}
void printArray(int arr[100][100], int n , int m){
    for (int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int arr[100][100];
    int rows , cols;
    printf("nhap so hang: ");
    scanf("%d",&rows);
    printf("nhap so cot: ");
    scanf("%d",&cols);
    if((rows <= 0 || rows >= 1000) && (cols <= 0 || cols >= 1000)){
        printf("so hang va so cot ko hop le");
    }else if(rows <= 0 || rows >= 1000){
        printf("so hang ko hop le");
    }else if(cols <= 0 || cols >= 1000){
        printf("so cot ko hop le");
    }else{
        printf("nhap cac phan tu cho mang:\n");
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                scanf("%d",&arr[i][j]);
            }
        }
        printf("mang la:\n");
        printArray(arr,rows,cols);
        if(rows == cols){
            totalMain(arr,rows);
            totalSubdiagonal(arr,rows);
        }else{
            printf("Khong ton tai duong cheo chinh va duong cheo phu");
        }
    }
    return 0;
}

