#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct Node {
  int data;
  struct Node *next;
};

typedef struct Node Node;

Node* createNode(int data){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void traversal(Node* head){
  Node* tmp = head;
  while(tmp!=NULL){
    printf("%d ", tmp->data);
    tmp = tmp->next;
  }
}

Node* insertatend(Node* head, int data){
  Node* tmp = head;
  while(tmp->next!=NULL){
    tmp = tmp->next;
  }
  Node* newNode = createNode(data);
  tmp->next = newNode;

  return tmp;
}

Node* insertAtBeginning(Node* head, int data){
  Node* newNode = createNode(data);
  newNode->next = head;
  return newNode;
}

Node* deleteNode(Node* head){
  Node* tmp = head;
  Node* prev = (Node*)malloc(sizeof(Node));
  while (tmp->next!=NULL){
    prev = tmp;
    tmp = tmp->next;
  } 
  prev->next = NULL;
  return head;
}


int main(){
  struct Node* head = createNode(1);
  head->next = createNode(2);
  head->next->next = createNode(3);
  head->next->next->next = createNode(4);
  traversal(head);
  insertatend(head, 5);
  printf("\n");
  insertatend(head, 5);
  insertatend(head, 5);
  head = insertAtBeginning(head, 0);
  head = deleteNode(head);
  traversal(head);
}
