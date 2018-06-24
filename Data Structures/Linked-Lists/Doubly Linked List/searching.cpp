#include<iostream>
using namespace std;


struct node {
 
  int data;
  node *next;
  node *prev;

};

/*searches the node containing the given data(integer in this case)
  node **head - address of the HEAD (beginning of linked list)
  int x - data to be searched
*/
node* search(node **head,int x){

  node *temp = *head;
  while(temp->data == x)
    temp=temp->next;
  return temp;
}

