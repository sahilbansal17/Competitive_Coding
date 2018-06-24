#include <iostream>

struct node {
 
  int data;
  node *next;
  node *prev;

};

/* Inserts new node at beginning/end of a list. 
   node** - address of the HEAD (beginning of linked list)
   int x-  value to be added in the linked list (integer in this example)
   int insertion_position - 0 for insertion at beginning
                            1- for insertion at end
*/
void insert(node**head, int x,int insertion_position) 
{ 
   node *new_node = new node;
   new_node->data = x;
   
   //1.if new node is to be inserted at beginning 
   if(insertion_position == 0){
     new_node->next = *head;
     new_node->prev =NULL;
     if((*head)!= NULL){                               //to check if linked list in not empty
       (*head)->prev= new_node;             
     } 
     (*head)= new_node;
     return;
   }
   
   //2. if new node is to be inserted at the end
   if(insertion_position == 1){
     node *temp = *head;
     new_node->next == NULL;
     if((*head)==NULL){
       new_node->prev = NULL;
       *head = new_node;
     }
     else{
       while(temp->next != NULL)  //to reach the last node of list
         temp=temp->next;
       temp->next = new_node;  
       new_node->prev = temp;
     } 
     return;
   }
}


/* Inserts the new node in between two nodes.
   node* given_node : pointer that contains the address of the node before/after which new node is
                     to be inserted.
   int x : data to be inserted in the node (integer in this example)
   int insertion_position : 0 for inserting before the given node.
                            1 for inserting after the given node.
*/ 
void insert_given_node(node* given_node, int x,int insertion_position){
  if(given_node==NULL){
    return;
  }
  node *new_node = new node;
  new_node->data = x;
  //1. inserting new node before the given node.
  if(insertion_position == 0){
    new_node->prev = given_node->prev;
    new_node->next = given_node;
    given_node->prev = new_node;
    return;
  }
  //2. inserting new node after the given node.
  if(insertion_position ==1){
    new_node->next = given_node->next;
    new_node->prev = given_node;
    given_node->next = new_node;
    return;
  }
}

  
    

   
   
   
