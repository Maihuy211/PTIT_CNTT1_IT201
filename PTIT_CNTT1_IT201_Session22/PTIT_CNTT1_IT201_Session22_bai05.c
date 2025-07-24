#include <stdio.h>
#include <stdlib.h>

void addEdge(int size , int matrix[][size], int u ,  int v ){
    matrix[u][v] = 1;
    matrix[v][u] = 1; 
}

int count(int n, int matrix[n][n] , int k){
    int count=0;
        for(int j = 0 ; j < n ; j++){
            if(matrix[k][j]==1){
                count++;
            }
        }
    return count;
}
int main() {
    int n ;
    int m ; 

    printf("nhap dinh: ");
    scanf("%d",&n);
    printf("nhap canh: ");
    scanf("%d",&m);
     
    int matrix[n][n]; 
    printf("so canh: \n");
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d",&u , &v);
        addEdge(n, matrix, u, v);
    }
    printf("\n");
    int k;
    printf("nhap k: ");
    scanf("%d",&k);
    int result = count(n,matrix,k);
    printf("%d",result);
    return 0;
}