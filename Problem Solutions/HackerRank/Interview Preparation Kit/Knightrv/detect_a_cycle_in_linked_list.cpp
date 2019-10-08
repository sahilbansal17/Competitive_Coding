/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head==NULL)
        return false;                   //We are taking a slow and a fast pointer to 
    Node *slow=head->next;              //to access the linked list where speed of fast
    if(slow->next==NULL)                //pointer is double to that of slow one.
        return false;                   //We are running a loop starting from head and continuing
    Node *fast=slow->next;              //it untill fast and slow pointer meet each other or
    while(fast!=NULL && slow!=NULL)     //either one of them becomes NULL.
    {                                   //If any one of them becomes NULL then there is no loop in linked list.
        if(fast==slow)                  //else they will meet.
            return true;
        slow=slow->next;
        if(fast->next!=NULL)
            fast=fast->next->next;
    }
    return false;
}