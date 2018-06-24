#include <iostream>
using namespace std;

struct node {
 
  int data;
  node *next;
  node *prev;

};

/*deletes a node of given address
    node** - address of the HEAD (beginning of linked list)
    given_node* - node to be deleted(its address is passed as argument)
*/
void del(node** head,node* given_node){
  node *temp = *head;
  //to check if given_node is the very first node of list
  if(given_node == *head){
    //to check if it is the only node in the list
    if(given_node->next== NULL){
      delete given_node;
      *head==NULL;                                     //empties the list by assigning null to HEAD
      return;
    }
    else{
      *head=given_node->next;                          //points HEAD to next node of the given node and makes it the first node of list
      given_node->next->prev== NULL; 
      delete given_node;
      return;           
    }
  }
  //if given node lies between two nodes
  while(temp->next!= given_node)
    temp=temp->next;
  temp->prev->next = given_node->next;                 //connect the two nodes between which given_node lies
  temp->next->prev = given_node->prev;
  delete given_node;
  return;
}
