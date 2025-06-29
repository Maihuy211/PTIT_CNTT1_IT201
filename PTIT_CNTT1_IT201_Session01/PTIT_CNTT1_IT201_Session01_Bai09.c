#include <stdio.h>
void printMatrix(int arr[100][100], int n , int m){
    printf("tat ca cac phan tr trong ma tran:\n");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
}
// do phuc tap thoi gian 0 (n^2)
// do phuc tap khong gian O(1)
void printMainDiagonal(int arr[100][100] , int size){
    printf("duong cheo ching trong ma tran la:\n");
    for(int i = 0 ; i < size ; i++){
        printf("%d",arr[i][i]);
    }
}
// do phuc tap O (n)
// do phuc tap khong gian O(1)
int main(){
    int arr[100][100] = { {1,2,3} , {4,5,6} , {7,8,9} };
    int n = 3 , m = 3;
    printMatrix(arr,n,m);
    printMainDiagonal(arr,n);
    return 0; 
}