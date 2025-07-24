#include <stdio.h>
#include <stdlib.h>

void printMatrix(int size, int matrix[][size]){
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
} 
int count(int n, int matrix[n][n]){
    int count=0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(matrix[i][j]==1){
                count++;
            }
        }
    }
    return count;
}
int main() {
    int n ;
    printf("nhap n: ");
    scanf("%d",&n);
    int matrix[5][5] = {
      {0,1,1,0,0},
      {1,0,1,1,0},
      {1,1,0,1,0},
      {0,1,1,0,1},
      {0,0,0,1,0}
    };
    // int matrix[n][n]; 
    // printf("nhap phan tu ma tran: \n");
    // for(int i = 0 ; i < n ; i++){
    //     for(int j = i + 1; j < n ; j++){
    //         scanf("%d",&matrix[i][j]);
    //     }
    // }
    printf("\n");
    printMatrix(n,matrix);

    printf("\n");
    int result = count(n,matrix);
    printf("%d",result);
    return 0;
}