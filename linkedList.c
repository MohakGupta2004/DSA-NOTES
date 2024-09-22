#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    while(ptr!=NULL){
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
        if(ptr==NULL){
            printf("NULL");
        }
}
 
 struct Node* insertAtBeginning(struct Node *head, int data){
     struct Node *ptr;
     ptr = (struct Node*)malloc(sizeof(struct Node));
     ptr->data = data;
     ptr->next = head;
     return ptr;
 }
 struct Node* insertAtIndex(struct Node *head, int data, int index){
     struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
     struct Node *temp =head;
     int i=0;
     while(i<index){
         temp = temp->next;
         i++;
     }
     ptr->data = data;
     ptr->next = temp->next;
     temp->next = ptr;
     return head;
 }
 struct Node* insertAtEnd(struct Node* head, int data){
     struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
     struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
     temp = head;
     while(temp->next!=NULL){
         temp=temp->next;
     }
     ptr->data = data;
     temp->next = ptr;
     ptr->next = NULL;
     return head;
 }
 
 struct Node* deleteFromBeg(struct Node*head){
     struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
     temp = head;
     head = head->next;
     free(temp);
     return head;
 }
 struct Node* deleteFromIndex(struct Node* head, int index){
     int i=0;
     
     struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
     struct Node *prev = (struct Node*)malloc(sizeof(struct Node));
     temp = head;
     while(i<index){
        prev = temp;
        temp = temp->next;
        i++;
     }
     prev->next = temp->next;
     return head;
 }
 struct Node* deleteFromEnd(struct Node* head){
     struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
     struct Node *prev = (struct Node*)malloc(sizeof(struct Node));
    temp = head;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    // free(temp);
    return head;
 }
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
 
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 
    // Link first and second nodes
    head->data = 7;
    head->next = second;
 
    // Link second and third nodes
    second->data = 11;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;
 
    linkedListTraversal(head);
    printf("\n");
    head=insertAtBeginning(head, 12);

    linkedListTraversal(head);
    printf("\n");
    head = insertAtIndex(head, 45, 3);
    linkedListTraversal(head);
    printf("\n");
    head = insertAtEnd(head,34);
    linkedListTraversal(head);
    head=deleteFromBeg(head);
    printf("\n");
    linkedListTraversal(head);
    head=deleteFromIndex(head, 1);
    printf("\n");
    linkedListTraversal(head);
    head=deleteFromEnd(head);
    printf("\n");
    linkedListTraversal(head);
    return 0;
}
