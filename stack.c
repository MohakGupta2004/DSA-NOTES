#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node {
  int data;
  struct Node* next;
};

struct Stack{
 struct Node* top; 
};

typedef struct Node Node;
typedef struct Stack Stack;


int isEmpty(Stack *s){
  return s->top == NULL;
}

void initStack(Stack *s){
 s->top = NULL;
}

Node* createNode(int data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}
void push(Stack *s, int data){
  Node* newNode = createNode(data); 
  newNode->next = s->top;
  s->top = newNode;
  printf("PUSHED %d\n", s->top->data);
}
void pop(Stack *s){
  if(isEmpty(s)){
    printf("Stack is empty");
    return;
  }
  int poppedData = s->top->data;
  Node* temp = s->top;
  s->top = s->top->next;
  free(temp);
  printf("%d\n", poppedData);
}

void peek(Stack* s){
  printf("%d", s->top->data);
}
int main(){
  Stack *s = (Stack*)malloc(sizeof(Stack));
  initStack(s);
  push(s, 10);
  push(s, 20);
  push(s, 30);
  pop(s);
  pop(s);
  pop(s);
}
