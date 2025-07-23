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
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}
void printGraph(Node* adjList[] ,int vertices) {
    for (int i = 0; i < vertices; i++) {
      Node* temp = adjList[i];
      while (temp != NULL) {
         printf("%d -> ", temp->vertex);
         temp = temp->next;
      }
      printf("NULL\n");
   }
}

int main() {
    Node* adjList[3];
    for (int i = 0; i < 3; i++) {
        adjList[i] = NULL;
    }
    printGraph(adjList,3);
    int startNode = 1;
    int endNode = 2;

    addEdge(adjList,startNode,endNode);
    printf("\n");
    printGraph(adjList,3);
    return 0;
}
