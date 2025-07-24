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

void addEdge(Node* adjList[] , int u, int v) {
    Node* newNode = createNode(v);
    if (adjList[u] == NULL) {
        adjList[u] = newNode;
    } else {
        Node* temp = adjList[u];
        while (temp->next != NULL){
            temp = temp->next;
        } 
        temp->next = newNode;
    }

    newNode = createNode(u);
    if (adjList[v] == NULL) {
        adjList[v] = newNode;
    } else {
        Node* temp = adjList[v];
        while (temp->next != NULL){
            temp = temp->next;
        }   
        temp->next = newNode;
    }
}
void printGraph(Node* adjList[] ,int vertices) {
    for (int i = 0 ; i < vertices ; i++) {
      Node* temp = adjList[i];
      printf("%d: ",i);
      while (temp != NULL) {
        printf("%d  ", temp->vertex);
        temp = temp->next;
      }
      printf("\n");
   }
}

int main() {
    int n;
    printf("nhap n: ");
    scanf("%d",&n);
    Node* adjList[n];
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    addEdge(adjList,0,1);
    addEdge(adjList,0,2);
    addEdge(adjList,1,2);
    addEdge(adjList,3,2);
    addEdge(adjList,1,3);
    addEdge(adjList,3,4);

    printf("\n");
    printGraph(adjList,n);
    return 0;
}
