// Name: Harsh Aryan
// Email-id: 12harsharyan@gmail.com
// THIS IS A PROGRAM TO IMPLEMENT LIST . IT CONSISTS OF INSERTION, DELETION, TRAVERSAL, SEARCH, REVERSE, SPLICE.

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
//worst case time complexity O(1)
//average case time complexity O(1)
//best case time complexity O(1)
//these are just constant time operations
// Space Complexity: O(1)

struct node *createNewNode(int d)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=d;
    return temp;
}

//function to add a new node at the beginning of the list
//worst case time complexity O(1)
//average case time complexity O(1)
//best case time complexity O(1)
//these are just constant time operations
// Space Complexity: O(1)


struct node *addAtBeg(struct node *head,struct node **end, int d)
{
    struct node *temp;
    temp=createNewNode(d);
    if(head==NULL)
    {
        head=temp;
        *end=temp;
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
//worst case time complexity O(1)
//average case time complexity O(1)
//best case time complexity O(1)
// Space Complexity: O(1)

struct node *addAtEnd(struct node *head,struct node **end, int d)
{
    struct node *temp;
    temp=createNewNode(d);
    if(head==NULL)
    {
        head=temp;
        *end=temp;
        return head;
    }
    else
    {
        (*end)->next=temp;
        *end=temp;
        return head;
    }
}



//function to add a new node at any required position, n of the list
//worst case time complexity O(N)
//average case time complexity O(N)
//best case time complexity O(1)
// Space Complexity: O(1)
//1 based indexing

struct node *insertAtPosn(struct node *head,struct node **end, int n, int d)
{
    int flag=0;
    struct node *temp=createNewNode(d);
    if(head==NULL)
        {   
            return temp;
            *end=temp;
        }
        
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
    if(temp2->next==NULL)
    flag=1;
    temp->next=temp2->next;
    temp2->next=temp;
    if(flag==1)
    *end=(*end)->next;
    
    return head;
}


//function to delete a node from the beginning of the list
//worst case time complexity O(1)
//average case time complexity O(1)
//best case time complexity O(1)
//these are just constant time operations
// Space Complexity: O(1)


struct node *deleteFromBeg(struct node *head,struct node **end)
{
    if(head==NULL)
        return;
    if(head->next==NULL)
    {
        *end=NULL;
        
    }
    head=head->next;
    return head;
}


//function to delete a node from the end of the list
//worst case time complexity O(N)
//average case time complexity O(N)
//best case time complexity O(1)
// Space Complexity: O(1)

struct node *deleteFromEnd(struct node *head,struct node **end)
{
    if(head==NULL)
        return;
    else if(head->next==NULL)
    {
        head=NULL;
        *end=NULL;
        return head;
    }

    else
    {
        struct node *temp1=head;
        while(temp1->next->next!=NULL)
        {
            temp1=temp1->next;
        }
        *end=temp1;
        temp1->next=NULL;
        return head;
        
    }
}

//function to traverse through the liked list and print all the nodes
//iterative approach
//worst case time complexity O(N)
//best case time complexity O(N)
// Inside the for loop, there is just a condition check ,
// Overall, time taken is O(n) thus.
// Space Complexity: O(1)

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
//worst case time complexity O(N)
//average case time complexity O(N)
//best case time complexity O(1)
// Inside the for loop, there is just a condition check ,
// Overall, time taken is O(n) thus.
// Space Complexity: O(1)

int search(struct node *head, int d)
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
//worst case time complexity O(N)
//average case time complexity O(N)
//best case time complexity O(N)
// Inside the for loop, there is just a condition check ,
// Overall, time taken is O(n) thus.
// Space Complexity: O(1)

struct node *reversal(struct node *head,struct node **end)
{
    *end=head;
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

//function to splice
//accepts three parameters, head, start and end,
//start and end are the indices from which and till which splicing is to be done
//indexing zero based, so first index is 0
//worst case time complexity O(N)
//average case time complexity O(N)
//best case time complexity O(1)
// Inside the for loop, there is just a condition check ,
// Overall, time taken is O(n) thus.
// Space Complexity: O(1)

struct node *splice(struct node *head,struct node **end, int start, int endd)
{
    if(head==NULL)
    return head;
    struct node *temp=head;
    int count=0;
    while(count<start && temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    head=temp;
    
    while(count<endd && temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    temp->next=NULL;
    *end=temp;
    return head;
    
}

//the main function to run the code

int main()
{
    int option = 0;
    int d, n, position;
    int start, endd;

    struct node *head = NULL;
    struct node *end;
    end=NULL;


//different options to select from what to do
// a menu is given to select from
//the menu repeats until the user selects 9 that is Exit

    while (option != 10 )
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
        printf("9.Splice the linked list\n");
        printf("10.Exit\n");

        scanf("%d", &option);

        //option for insertion at beginning
        //addAtBeg function to be called

        if (option == 1)
        {
            printf("Enter the value to be inserted :\n");
            scanf("%d", &d);
            head=addAtBeg(head,&end,d);
            printf("Insertion Successful\n");
        }

        //option for insertion at end
        //addAtEnd function to be called


        if (option == 2)
        {
            printf("Enter the value to be inserted :\n");
            scanf("%d", &d);
            head=addAtEnd(head,&end,d);
            printf("Insertion Successful\n");
        }

        //option for insertion at any required position
        //insertAtPosn function to be called

        if (option == 3)
     
         {
            printf("Enter the value to be inserted :\n");
            scanf("%d", &d);
            printf("Enter the position where you want to insert : \n");
            scanf("%d", &n);
            head=insertAtPosn(head,&end,n,d);
            printf("Insertion Successful\n");
        }

        //option to delete a node from the beginning
        //deleteFromBeg function to be called

        if (option == 4)
        {   head=deleteFromBeg(head,&end);
            printf("Deletion Successful\n");
        }

        //option to delete a node from the end
        //deleteFromEnd function to be called

        if (option == 5)
        {   head=deleteFromEnd(head,&end);
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
            head=reversal(head,&end);
            printf("Reversal done:\n");
        }
        
        
        //option to splice the linked list
        //splice function called
        if (option == 9)
        {
            
            printf("From which index do you want to splice?\n");
            scanf("%d", &start);
            printf("Till which index do you want to splice? \n");
            scanf("%d", &endd);
            head=splice(head,&end,start,endd);
            printf("Splicing done:\n");
        }

    }
    return 0;
}
