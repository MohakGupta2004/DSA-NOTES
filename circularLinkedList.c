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
  newNode->next = newNode;
  return newNode;
}

void traversal(Node* head){
  if (head == NULL) return;  // If the list is empty, return
  
  Node* tmp = head;
  do {
    printf("%d ", tmp->data);
    tmp = tmp->next;
  } while(tmp != head);  // Stop when we loop back to the head
  printf("\n");
}

Node* insertatend(Node* head, int data){
  if(head == NULL) return createNode(data);
  Node* tmp = head;
  while(tmp->next!=head){
    tmp = tmp->next;
  }
  Node* newNode = createNode(data);
  tmp->next = newNode;
  newNode->next = head;
  return head;
}

Node* insertAtBeginning(Node* head, int data){
  Node* newNode = createNode(data);
  if (head == NULL) {
    return newNode;  // If the list is empty, the new node is both the head and the last nod
  } 
  Node* tmp = head;
  while(tmp->next!=head){
    tmp = tmp->next;
  } 
  tmp->next = newNode;
  newNode->next = head;
  return newNode; 
}

Node* deleteNode(Node* head) {
  if (head == NULL) return NULL;  // If the list is empty, return NULL
  
  if (head->next == head) {  // If there's only one node in the list
    free(head);
    return NULL;  // The list will be empty after deletion
  }

  Node* tmp = head;
  // Traverse to the last node
  while (tmp->next != head) {
    tmp = tmp->next;
  }

  Node* tempHead = head;
  head = head->next;  // Move the head pointer to the next node
  tmp->next = head;   // Last node points to the new head

  free(tempHead);  // Free the old head
  return head;
}


int main(){
  struct Node* head = createNode(1);
  head = insertatend(head, 2);
  head = insertatend(head, 3);
  head = insertatend(head, 4);
  head = insertatend(head, 5);
  head = insertAtBeginning(head, 0);
  traversal(head);
  head = deleteNode(head);
  traversal(head);
}
