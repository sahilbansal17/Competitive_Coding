//This program shows how various operations can be performed on
//a Doubly Linked List.
#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
};

//Inserts new node at beginning/end of a list.
// node** - address of the HEAD (beginning of linked list)
// int x-  value to be added in the linked list (integer in this example)
//int insertion_position - 0 for insertion at beginning
//                         1- for insertion at end
void insertNode(node**head, int x, int insertion_position){
    node *new_node = new node;
    new_node->data = x;
    //1.if new node is to be inserted at beginning
    if(insertion_position == 0){
        new_node->prev = NULL;
        //to check if linked list in not empty
        if((*head)!= NULL){
            (*head)->prev = new_node;
            new_node->next = (*head);
        }
        else
            new_node->next = NULL;
        (*head)= new_node;
        return;
    }

    //2. if new node is to be inserted at the end
    if(insertion_position == 1){
        node *temp = *head;
        new_node->next == NULL;
        //to reach the last node of list
        while(temp->next != NULL)
            temp=temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        return;
    }
}


//Inserts the new node in between two nodes.
//node* given_node : pointer that contains the address of the node before/after which new node is
//                     to be inserted.
// int x : data to be inserted in the node (integer in this example)
// int insertion_position : 3 for inserting before the given node.
//                            4 for inserting after the given node.
void insertGivenNode(node* given_node, int x,int insertion_position){
    if(given_node==NULL)
        return;
    node *new_node = new node;
    new_node->data = x;
    //1. inserting new node before the given node.
    if(insertion_position == 3){
        new_node->prev = given_node->prev;
        new_node->next = given_node;
        given_node->prev->next = new_node;
        given_node->prev = new_node;
        return;
    }
    //2. inserting new node after the given node.
    if(insertion_position ==4){
        new_node->next = given_node->next;
        new_node->prev = given_node;
        given_node->next->prev = new_node;
        given_node->next = new_node;
        return;
    }
}
//TIME COMPLEXITY : O(n) in the worst case (that is insertion of node at the end)
//                  since it requires traversing throught the list
//                  i.e. while loop is executed x times if x nodes are present.


//Reverses a Doubly Linked List i.e. it swaps prev and next of every single node and
//  head points to the last node in original list after.
// Take the address of head as an agrument.
void reverseList(node **head){
    node *temp = NULL;
    node *current = *head;
    //checks if the list contains only one node
    if((*head)->next==NULL)
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
//TIME COMPLEXITY - O(n) since it requires traversing every single node in the list
//to reverse the list i.e. while loop is executed x times if x nodes are present


//Searches the node containing the given data(integer in this case)
//node **head - address of the HEAD (beginning of linked list)
//int x - data to be searched
node* searchNode(node **head,int x){
    node *temp = *head;
    while(temp!=NULL){
        if(temp->data == x)
            return temp;
        temp=temp->next;
    }
    //if there exists no such node
    if(temp==NULL)
        return NULL;
}
//TIME COMPLEXITY - O(n) since it requires travesring all the elements until the node is found. In worst case,
//node will be present at last or not present at all i.e. while loop is executed x times if x nodes are present.


// Prints/displays data from every node in list.
//   node** - address of the HEAD (beginning of linked list)
void displayList(node **head){
    node *temp= *head;
    while(temp!=NULL){
        cout<<endl<<temp->data;
        temp = temp->next;
    }
    return;
}
//Time Complexity - O(n) since it requires visiting each node of list in
//order to display data of entire list i.e. while loop is executed x times if x nodes are present.


//Deletes a node of given address
//    node** head - address of the HEAD (beginning of linked list)
//    node *given_node - node to be deleted(its address is passed as argument)
void deleteNode(node** head, node* given_node){
    node *temp = *head;
    //to check if given_node is the very first node of list
    if(given_node == *head){
        //to check if it is the only node in the list
        if(given_node->next== NULL){
            //empties the list by assigning null to HEAD
            *head==NULL;
        }
        else{
            //points HEAD to next node of the given node and makes it the first node of list
            *head=given_node->next;
            given_node->next->prev== NULL;
        }
    }
    //if given node lies between two nodes
    else{
        while(temp->next!= given_node)
            temp=temp->next;
        temp->next = given_node->next;
        //if node is not the last node
        if(given_node->next != NULL)
            given_node->next->prev = temp;
     }
    delete given_node;
    return;
}
// TIME COMPLEXITY :  O(n) (worst case) because every node has to be visited once
//                    i.e. while loop is executed x times if x nodes are present
//                    if node is present at the end or is present between two nodes.

int main(){
    node *head = NULL;
    int n, data_value, choice, search_value, node_value, delete_node_value;
    node *given_node, *delete_node;
    cout<<"Please enter number of nodes to be inserted : ";
    cin>>n;
    for(int i = 0; i<n; i++){
        cout<<"Enter the value to be inserted in node : ";
        cin>>data_value;
        cout<<"Do you want node to be inserted at:"<<endl<<"1.Beginning(0)"<<endl<<"2.End(1)"
             <<endl<<"3.After a given node(3)"<<endl<<"4.Before a particular node(4)"
             <<endl<< "Please enter your choice : ";
        cin>>choice;
        switch(choice){
            case 0:
            case 1:
                insertNode(&head, data_value, choice);
                break;
            case 3:
            case 4:
               cout<<"Enter the value after/before which you want to insert new node : ";
               cin>>node_value;
               given_node = searchNode(&head,node_value);
               insertGivenNode(given_node, data_value, choice);
               break;
            default:
               cout<<"Please enter a valid choice"<<endl;
        }
    }
    displayList(&head);
    cout<<"Enter the value to be searched for: ";
    cin>>search_value;
    node *result_node = searchNode(&head, search_value);
    cout<<endl<<"Address of the searched node is: "<<result_node;
    cout<<"Enter the value of node to be deleted : ";
    cin>>delete_node_value;
    delete_node = search(&head,delete_node_value);
    deleteNode(&head,delete_node);
    reverseList(&head);
    displayList(&head);
}
