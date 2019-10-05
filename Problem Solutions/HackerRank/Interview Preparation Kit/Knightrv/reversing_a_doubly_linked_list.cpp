// Complete the reverse function below.

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
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    DoublyLinkedListNode *curr,*root;
    curr=head->next;
    root=head->prev;
    while(curr!=NULL)               //here we are just interchanging the next and prev pointer of each node
    {                               //and at last we are naming the last node as head.
        head->next=root;
        head->prev=curr;
        root=head;
        head=curr;
        curr=curr->next;
    }
    head->prev=curr;
    head->next=root;
    return head;

}

