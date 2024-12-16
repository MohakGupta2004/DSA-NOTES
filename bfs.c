
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define n 100 

struct Queue {
    int arr[n];
    int front, rear;
};

typedef struct Queue Queue;

int isFull(Queue* q) {
    return q->rear == n - 1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->arr[++q->rear] = data;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int dequeuedData = q->arr[q->front];
    q->front++;
    if (q->front > q->rear) {  // Reset queue if empty
        q->front = q->rear = -1;
    }
    return dequeuedData;
}

void bfs(int arr[MAX][MAX], int v, int startIdx) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    initQueue(q);
    int visited[MAX] = {0};
    visited[startIdx] = 1;
    enqueue(q, startIdx);
    while (!isEmpty(q)) {
        int curr = dequeue(q);
        printf("%d ", curr);
        for (int i = 0; i <= v; i++) {  // Fix indexing here
            if (arr[curr][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    free(q);  // Don't forget to free the allocated memory
}

void addedge(int adj[MAX][MAX], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

int main() {
  int adj[MAX][MAX] = {0};
  int v = 5;
  addedge(adj, 1,2);
  addedge(adj, 2,4);
  addedge(adj, 1,3);
  addedge(adj, 3,4);
  addedge(adj, 4,5);
  addedge(adj, 2,5);    
  bfs(adj, v, 1);  // Start BFS from vertex 0 (0-based indexing)
  return 0;
}
