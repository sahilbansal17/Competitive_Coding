#include<iostream>
using namespace std;

struct node {
 
  int data;
  node *next;
  node *prev;

};
/* Prints/displays data from every node in list.
   node** - address of the HEAD (beginning of linked list)
*/

void display(node **head){
  
  node *temp= *head;
   while(temp->next!=NULL){
     cout<<temp->data;
     temp = temp->next;
   }
   return;
};
   
  

