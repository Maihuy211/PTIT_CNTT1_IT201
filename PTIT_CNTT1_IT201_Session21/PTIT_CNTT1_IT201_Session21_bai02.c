#include <stdio.h>

void addEdge(int matrix[4][4], int firstNode, int secondNode){
    matrix[firstNode][secondNode] = 1;
    matrix[secondNode][firstNode] = 1; 
}

void printMatrix(int matrix[4][4] , int size){
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int matrix[4][4] = {
        {0,0,0},
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    printMatrix(matrix,4);

    addEdge(matrix,0,1);
    addEdge(matrix,0,2);
    addEdge(matrix,1,2);
    addEdge(matrix,2,3);

    printf("\n");
    printMatrix(matrix,4);

    return 0;
}