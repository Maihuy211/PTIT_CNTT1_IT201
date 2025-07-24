#include <stdio.h>

void addEdge(int size , int matrix[][size], int firstNode, int secondNode ){
    matrix[firstNode][secondNode] = 1;
    matrix[secondNode][firstNode] = 1; 
}

void printMatrix(int size, int matrix[][size]){
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    int matrix[n][n];

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            matrix[i][j] = 0;
        }
    }

    printMatrix(n,matrix);
    addEdge(n,matrix,0,1);
    addEdge(n,matrix,0,2);
    addEdge(n,matrix,1,2);
    addEdge(n,matrix,3,2);
    addEdge(n,matrix,1,3);
    addEdge(n,matrix,3,4);

    printf("\n");
    printMatrix(n,matrix);

    return 0;
}