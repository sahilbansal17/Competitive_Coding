/* Inserts a new node in a Circular Linked List.
  There could be 5 cases - 1.List is empty and adding the node.
                           2.List is not empty and adding the node in the beginning.
                           3.Adding the node at last.
                           4.Adding the node after a given node.
                           5.Adding the node before a given node.

*/

struct node {
 
  int data;
  node *next;
};

/* Inserts new node at beginning/end of a list. 
   node **head - address of the HEAD (beginning of linked list)
   int x-  value to be added in the linked list (integer in this example)
   int insertion_position - 0 for insertion at beginning
                            1 for insertion at end
*/
void insert(node **head, int x,int insertion_position) 
{ 
   node *new_node = new node;
   new_node->data = x;
   //1.if new node is to be inserted at beginning 
   if(insertion_position == 0){
      if(*head == NULL){                                          //to check if this the very first(only) node in the list
        new_node->next = *head;
        return;
      }                                     
      node *temp = *head;
      while(temp->next!=NULL)
       temp = temp->next;
      temp->next = new_node;                                     //last node's next should point to first node
      *head = new_node;                                   
      return;
   }
   //2. if new node is to be inserted at the end
   if(insertion_position == 1){
      node *temp = *head;
      while(temp->next != (*head))
        temp = temp->next;
      temp->next = new_node;
      new_node->next = *head;
      return;
    }
};

/* Inserts new node after/before a given_node 
   node** - address of the HEAD (beginning of linked list)
   node *given_node - node before/after which the new node has to be inserted
   int x-  value to be added in the linked list (integer in this example)
   int insertion_position - 0 for insertion before the given_node
                            1- for insertion after the given_node
*/

void insert_given_node(node **head,node *given_node, int x,int insertion_position){
  if(given_node==NULL){
    return;
  }
  node *new_node = new node;
  new_node->data = x;
  //1. inserting new node before the given node.
  if(insertion_position == 0){
    new_node->next = given_node;
    node *temp = *head;
    while(temp->next == given_node)
      temp = temp->next;                                                 //make the node which exists before given_node to point to new_node
    temp->next = new_node;
    return;
  }
  //2. inserting new node after the given node
  if(insertion_position == 1){
    new_node->next = given_node->next;
    given_node->next = new_node;
    return;
  }
};

 int main(){
   
   
 
  


/* Time Complexity - O(1) for 1.adding node when list is empty
                              2. adding node after a given node.
                     O(n) for 1. adding node at the beginning of a non-empty list.
                              2. adding node at the end
                              3. adding node before a given node.
*/ 





