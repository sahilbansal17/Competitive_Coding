#include<iostream>
using namespace std;

struct node {
 
  int data;
  node *next;
  node *prev;

};

void reverse(node **head){
  
  node *temp = NULL;
  node *current = *head;
  if((*head)->next==NULL)  //checks if the list contains only one node
    return;
    
  // to reverse, we need to swap prev and next of all the nodes of list
  while(current!=NULL){
    
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;              
    current = current->prev;

  }
  //HEAD should now point to the current node in the reversed list
  *head = temp->prev;
  return;
}

