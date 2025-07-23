#include <stdio.h>

void addEdge(int matrix[3][3], int firstNode, int secondNode){
    matrix[firstNode][secondNode] = 1;
    matrix[secondNode][firstNode] = 1; 
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
    int  firstNode = 1;
    int secondNode = 2;
    addEdge(matrix,firstNode,secondNode);

    printf("\n");
    printMatrix(matrix,3);

    return 0;
}