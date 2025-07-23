#include <stdio.h>
#include <stdlib.h>

void addEdge(int matrix[3][3], int startNode, int endNode){
    matrix[startNode][endNode] = 1;
}

void printMatrix(int matrix[3][3] , int size){
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int matrix[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    printMatrix(matrix,3);

    addEdge(matrix, 1 ,0);
    addEdge(matrix, 1 ,2);
    addEdge(matrix, 2 ,0);

    printf("\n");
    printMatrix(matrix,3);

    return 0;
}
