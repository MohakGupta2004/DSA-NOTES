#include <stdio.h>
#include <stdlib.h>
#define n 10

struct Stack{
  int array[n];
  int top;
};

typedef struct Stack Stack;

int isEmpty(Stack *s){
  return s->top == -1;
}

int isFull(Stack *s){
  return s->top == n;
}

void initStack(Stack *s){
 s->top = -1; 
}

void push(Stack *s, int data){
  if(isFull(s)){
    printf("Already Full\n");
    return;
  }
  s->array[++s->top] = data;
  printf("PUSHED %d\n", data);
}

void pop(Stack *s){
  if(isEmpty(s)){
    printf("Empty\n");
    return;
  } 
  printf("POPPED DATA %d", s->array[s->top]);
  s->array[s->top--];
 }

int main(){
  Stack *s = (Stack*)malloc(sizeof(Stack));
  initStack(s);
  push(s, 10);
  push(s, 20);
  pop(s);
}
