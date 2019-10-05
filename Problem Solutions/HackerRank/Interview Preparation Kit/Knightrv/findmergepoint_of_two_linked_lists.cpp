/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *head1, Node *head2)
{
    int c1=1;
    int c2=1;
    Node* temp1, *temp2;
    temp1=head1;
    temp2=head2;                    // we are counting number of nodes in 1st linked list and
    while(temp1->next!=NULL)        // 2nd linked list and then we run a loop from the linked list 
    {                               // having greater number of nodes and continue it untill number of
        temp1=temp1->next;          //nodes in both linked list become equal
        c1++;                       // After that we check if the nodes in both linked list are equal or not.
    }                               //If equal then we print the data else continue the loop untill either of them
    while(temp2->next!=NULL)        //become NULL.
    {
        temp2=temp2->next;
        c2++;
    }
    temp1=head1;
    temp2=head2;
    while(c1>c2)
    {
        temp1=temp1->next;
        c1--;
    }
    while(c2>c1)
    {
        temp2=temp2->next;
        c2--;
    }
    while(temp1!=temp2)
    {
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return temp1->data;
}