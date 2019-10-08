// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode *temp=new DoublyLinkedListNode(data);
    if(data<head->data)
    {
        temp->next=head;
        head->prev=temp;
        head=temp;                          //Here we are checking the data value with node's data and as soon as node's data becomes larger 
    }                                       //than given data we stop the loop(or if linked list ends) and then go to previous node and make it point to
    else                                    //and then temp->next points to current node(if NOt null).                                      
    {
        DoublyLinkedListNode* curr=head;
        while(curr->next!=NULL && curr->data<data)
        {
           curr=curr->next; 
        }
        if(curr->data>=data)
        {
            DoublyLinkedListNode* root;
            root=curr->prev;
            root->next=temp;
            temp->prev=root;
            temp->next=curr;
            curr->prev=root;
        }
        else
        {
            curr->next=temp;
            temp->prev=curr;
        }
    }
    return head;
}

