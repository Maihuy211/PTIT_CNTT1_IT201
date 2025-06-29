#include <stdio.h>
#include <stdlib.h> 
void printArray(int arr[100][100], int n , int m){
    for (int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
void sumRow(int arr[100][100], int m, int k) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
        sum += arr[k-1][j];
    }
    printf("sum = %d\n",sum);
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
        int k;
        printf("nhap so hang muon tinh tong: ");
        scanf("%d",&k);
        if(k < 0 || k >= rows){
            printf("Hang can tinh ko hop le");
        }else{
            sumRow(arr,cols,k);
        }
    }
    return 0;
}

