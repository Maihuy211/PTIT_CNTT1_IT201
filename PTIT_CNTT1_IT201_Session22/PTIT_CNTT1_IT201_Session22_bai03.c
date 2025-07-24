#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void printMatrix(int size, int matrix[][size]){
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
} 
Node* insertNode(Node* head , int v){
    Node* newNode = createNode(v);
    if (head == NULL){
        return newNode;
    }   
    Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }   
    temp->next = newNode;
    return head;
}
void change(int n ,int matrix[n][n], Node* adjList[]){ 
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL; 
        for (int j = 0; j < n; j++) {
             if (matrix[i][j] == 1) {
                adjList[i] = insertNode( adjList[i],j);
            }
        }
    }
}

void printGraph(Node* adjList[] ,int vertices) {
    for (int i = 0 ; i < vertices ; i++) {
      Node* temp = adjList[i];
      printf("%d: ",i);
      while (temp != NULL) {
        printf("%d -> ", temp->vertex);
        temp = temp->next;
      }
      printf("NULL\n");
   }
}
int main() {
    int n ;
    printf("nhap n: ");
    scanf("%d",&n);
    // int matrix[5][5] = {
    //   {0,1,1,0,0},
    //   {1,0,1,1,0},
    //   {1,1,0,1,0},
    //   {0,1,1,0,1},
    //   {0,0,0,1,0}
    // };
    int matrix[n][n]; 
    printf("nhap phan tu ma tran: \n");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("\n");
    Node* adjList[n];
    printMatrix(n,matrix);
    change(n ,matrix,adjList);

    printf("\n");
    printGraph(adjList,n);

    return 0;
}