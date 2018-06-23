/* THIS IS A PROGRAM TO IMPLEMENT LIST . IT CONSISTS OF INSERTION, DELETION, TRAVERSAL, SEARCH, REVERSE.*/

#include <stdio.h>
#include <stdlib.h>

//declaring  a structure named node
//a node is the smallest unit of  a linked list

struct node
{
    int data;
    struct node *next;
};

//function to create a node

struct node *create_new_node(int d)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=d;
    return temp;
}

//function to add a new node at the beginning of the list

struct node *add_at_beg(struct node *head, int d)
{
    struct node *temp;
    temp=create_new_node(d);
    if(head==NULL)
    {
        head=temp;
        return head;
    }
    else
    {
        temp->next=head;
        head=temp;
        return head;
    }
}

//function to add a new node at the end of the list

struct node *add_at_end(struct node *head, int d)
{
    struct node *temp;
    temp=create_new_node(d);
    if(head==NULL)
    {
        head=temp;
        return head;
    }
    else
    {
        struct node *temp2=head;
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;
        return head;
    }
}


//function to add a new node at any required position, n of the list

struct node *insert_at_posn_n(struct node *head,int n,int d)
{
    struct node *temp=create_new_node(d);
    if(head==NULL)
        return temp;
    if(n==1)
    {
        temp->next=head;
        head=temp;
        return temp;
    }
    n--;
    struct node *temp2=head;
    n--;
    while(n>0)
    {
        n--;
        temp2=temp2->next;

    }
    temp->next=temp2->next;
    temp2->next=temp;
    return head;
}

//function to delete a node from the beginning of the list

struct node *delete_from_beg(struct node *head)
{
    if(head==NULL)
        return;
    head=head->next;
    return head;
}

//function to delete a node from the end of the list

struct node *delete_from_end(struct node *head)
{
    if(head==NULL)
        return;
    else if(head->next==NULL)
    {
        head=NULL;
        return head;
    }

    struct node *temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}

//function to traverse through the liked list and print all the nodes
//iterative approach

void traversal(struct node *head)
{
    if(head==NULL)
        return head;
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

//function to search any number
//function will return the index of the first occurence of the element
//search will return result on 1 based indexing
//iterative approach

int search(struct node *head,int d)
{
    int flag=-1;
    if(head==NULL)
    {
        return -1;
    }
    struct node *temp=head;
    int i=1;
    while(head!=NULL)
    {
        if(temp->data==d)
        {
            flag=i;
            break;
        }
        temp=temp->next;
        i++;
    }
    return flag;
}

//function to reverse a linked list
//iterative approach

struct node *reversal(struct node *head)
{
    if(head==NULL)
        return head;
    else if(head->next==NULL)
        return head;
    else
    {
        struct node *prev=NULL;
        struct node *curr=head;
        struct node *nextt=NULL;

        while(curr!=NULL)
        {
            nextt=curr->next;
            //reversing the actual link
            curr->next=prev;
            //further changes
            prev=curr;
            curr=nextt;

        }
        head=prev;
        return head;
    }
}

//the main function to run the code

int main()
{
    int option = 0;
    int d,n,position;

    struct node *head=NULL;

//different options to select from what to do
// a menu is given to select from
//the menu repeats until the user selects 9 that is Exit

    while (option != 9 )
    {
        printf("\n\nPress the index of the work to be performed : \n");
        printf("1.Insert at beginning\n");
        printf("2.Insert at end\n");
        printf("3.Insert at n-th position\n");
        printf("4.Delete from beginning\n");
        printf("5.Delete from end\n");
        printf("6.Traverse\n");
        printf("7.Search\n");
        printf("8.Reverse the linked list\n");
        printf("9.Exit\n");

        scanf("%d", &option);

        //option for insertion at beginning
        //add_at_beg function to be called

        if (option == 1)
        {
            printf("Enter the value to be inserted :\n");
            scanf("%d", &d);
            head=add_at_beg(head,d);
            printf("Insertion Successful\n");
        }

        //option for insertion at end
        //add_at_end function to be called


        if (option == 2)
        {
            printf("Enter the value to be inserted :\n");
            scanf("%d", &d);
            head=add_at_end(head,d);
            printf("Insertion Successful\n");
        }

        //option for insertion at any required position
        //ainsert_at_posn_n function to be called

        if (option == 3)
        {
            printf("Enter the value to be inserted :\n");
            scanf("%d", &d);
            printf("Enter the position where you want to insert : \n");
            scanf("%d", &n);
            head=insert_at_posn_n(head,n,d);
            printf("Insertion Successful\n");
        }

        //option to delete a node from the beginning
        //delete_from_beg function to be called

        if (option == 4)
        {   head=delete_from_beg(head);
            printf("Deletion Successful\n");
        }

        //option to delete a node from the end
        //delete_from_end function to be called

        if (option == 5)
        {   head=delete_from_end(head);
            printf("Deletion Successful\n");
        }

        //option to traverse and print the list
        //traverse function to be called

        if (option == 6)
        {
            printf("Here is the list:\n");
            traversal(head);
        }


        //option to search
        //element to be search is to be scanned
        //search function to be called

        if (option == 7) {
            printf("Enter the value to search : \n");
            scanf("%d", &n);
            position=search(head,n);
            if (position != -1)
                printf("Value found at position : %d\n", position);
            else
                printf("Value not found !\n");
        }

        //option to reverse the linked list
        //does not print the reversed linked list
        //reversal function called

        if (option == 8)
        {
            head=reversal(head);
            printf("Reversal done:\n");
        }

    }
    return 0;
}

