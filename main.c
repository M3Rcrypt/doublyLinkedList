#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Struct for implementing Doubly Linked List
struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* head; //Global Scope

// Create a new node
struct Node* GetNewNode(int x){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode; 
}

// insert an element at the beginning (index = 0)
void InsertAtHead(int x){
  struct Node* newNode = GetNewNode(x);
  if(head == NULL){
    head = newNode;
    return;
  }
  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}

// insert an element to the last position (index = size - 1)
void InsertAtTail(int x){
  struct Node* newNode = GetNewNode(x);
  struct Node* p = head;
  if(head == NULL){
    head = newNode;
    return;
  }
  while(p->next != NULL){
    p = p->next;
  }
  p->next = newNode;
  newNode->prev = p;
  newNode->next = NULL;
}

// insert an element to the position n (n = index + 1)
void InsertNthPosition(int x, int pos){
  struct Node* newNode = GetNewNode(x);
  struct Node* p = head;
  if(pos==1){
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return;
  }
  for(int i = 0; i < pos-2; i++) {
      if(p != NULL) {
        p = p->next;
      }
  }  
  if(p != NULL) {
    newNode->next = p->next;
    newNode->prev = p;
    p->next = newNode;
    if(newNode->next != NULL)
      newNode->next->prev = newNode;  
  } 
}

// print the linked list without reversing
void Print(){
  printf("\nForward Pirnt: ");
  struct Node* p = head;
  while(p != NULL){
    printf(" %d", p->data);
    p = p->next;
  }
  printf("\n");
}

// print the linked list in reverse order
void ReversePrint(){
  struct Node* p = head;
  while(p -> next != NULL){
    p = p->next;
  }
  printf("\nReverse Print: ");
  while(p != NULL){
    printf(" %d",p->data);
    p = p->prev;
  }
  printf("\n");
}

// main function to illustrate thge functions (it can be changed for specific use cases)
int main(void) {
  int size, num;
  printf("Please enter the size of Doubly Linked List: ");
  scanf("%d",&size);
  for(int i = size; i > 0; i--){
    printf("\nPlease enter element %d:", i);
    scanf("%d",&num);
    InsertAtHead(num);
  }
  Print();
  ReversePrint();
  InsertAtTail(22);
  InsertAtTail(35);
  InsertAtTail(10);
  InsertAtTail(20);
  InsertAtTail(30);
  Print();
  InsertNthPosition(31, 4);
  Print();
  
}