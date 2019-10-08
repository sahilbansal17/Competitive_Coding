// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* temp=new SinglyLinkedListNode(data);
    if(head==NULL)
        return temp;
    else if(position==0)
    {
        temp->next=head;
        head=temp;                             //Here we are checking if position is 0 or not and if it is we make temp as head and temp->next equal to previous head.
    }                                           //else we are taking 2 pointers one stores previous node of the curr node and then make suitable arrangements for the temp node.
    else
    {                                           
        SinglyLinkedListNode* curr=head;
        SinglyLinkedListNode* root=head;
        int i=0;
        while(i<position && curr!=NULL)
        {
            root=curr;
            curr=curr->next;
            i++;
        }
        if(curr==NULL)
        {
            root->next=temp;
        }
        else
        {
            root->next=temp;
            temp->next=curr;
        }
    }
    return head;

}

