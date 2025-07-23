#include <stdio.h>

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
    int  startNode = 1;
    int endNode = 2;
    addEdge(matrix,startNode,endNode);

    printf("\n");
    printMatrix(matrix,3);

    return 0;
}