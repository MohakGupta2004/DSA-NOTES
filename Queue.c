// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue* q){
    if(q->rear == q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue* q){
    if(q->front == q->rear){
        return 1;
    }
    return 0;
}
void enqueue(struct Queue* q, int data){
    if(isFull(q)){
        return;
    }
    q->rear++;
    q->arr[q->rear] = data;
}

int dequeue(struct Queue* q){
    int a;
    if(isEmpty(q)){
        q->front = -1;
        q->rear = -1;
    } else {
    q->front++;
    a = q->arr[q->front];
    return a;
    }
}

int main() {
    // Write C code here
    struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
    q->size = 5;
    q->front = q->rear = -1;
    q->arr = (int*)malloc(q->size*sizeof(int));
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    return 0;
}
