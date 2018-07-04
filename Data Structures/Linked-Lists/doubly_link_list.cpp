#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

typedef struct node type;

type *first = new type;
type *last = new type;

int length = 0 ;

void insertAtEnd(int);
void insertAtBeg(int);
void insertByIndex(int);
void traversal(type*);

void insertAtEnd(int data)
{
	type *temp = new type;
	temp->prev = last;
	temp->data = data;
	temp->next = NULL;

	if( first == NULL )
	{
		first = temp;
		last = temp;
	}
	else
	{
		last->next = temp;
		last = temp;
	}
	temp = NULL;
	delete temp;
	length++;
}

void insertAtBeg(int data)
{
	type *temp = new type;
	temp->prev = NULL;
	temp->data = data;
	temp->next = first;

	if(first != NULL)
	{
		first->prev = temp;
		first = temp;
	}
	else
	{
		first = temp;
		last = temp;
	}
	temp = NULL;
	delete temp;
	length++;
}

void insertByIndex(int data)
{
	type *temp = new type;
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;

	if(first == NULL)
	{
		insertAtBeg(data);
	}
	else
	{
		std::cout<<"Values in the list are : \n";
		traversal(first);

		std::cout<<"\nEnter the position where to be inserted\n Indexing start from 1\n";
        int pos;
        std::cin>>pos;

		if(pos == 1)
		{
			insertAtBeg(data);
		}
		else if(pos == length+1)
		{
			insertAtEnd(data);
		}
		else
		{
			assert(pos <= length+1);

			type *prev = first;
			type *traverse = first->next;

			for(int i=2; i<=length ; i++)
			{
				if(i == pos)
				{
					prev->next = temp;
					temp->prev = prev;
					temp->next = traverse;
					traverse->prev = temp;
				}
				prev = traverse;
				traverse = traverse->next;
			}
			length++;
		}
	}
	delete temp;
}

void deleteFromEnd()
{
	if(first != NULL)
	{	type *temp = last;
		last = last->prev;
		last->next = NULL;
		delete temp;
	}
	else
	{
		std::cout<<"Value is not existed";
	}
}

void deleteFromBeg()
{
	if(first != NULL)
	{
		type *temp = first;
		first = first->next;
		first->prev = NULL;
		delete temp;
	}
	else
	{
		std::cout<<"Value is not existed";
	}
}

void deleteByIndex(int index)
{
	type *traverse = first;
    type *prev = first;
    type *temp;
    bool flag = false;
    for(int i=1; i <= length ; i++)
	{
                if(i == index)
                {
                        flag = true;
                        if(traverse == first)
                        {
                                temp = traverse;
                                first = first->next;
                                first->prev = NULL;
                                delete temp;
                                break;
                        }
                        else
                        {
                                temp = traverse;
                                prev->next = traverse->next;
                                traverse = traverse->next;
                                traverse->prev = prev;
				traverse->prev = prev;
                                delete temp;
                                break;
                        }
                }
                prev = traverse;
                traverse = traverse->next;
        }
        if(!flag)
        {
                std::cout<<"Value Does not exist to be deleted"<<'\n';
        }
        else
        {
                length--;
        }
}

void traversal(type *traverse = first)
{
	int len = length;
	for(int i=1 ; i <= len ; i++)
	{
		std::cout<<"Index "<<i<<" has value : "<<traverse->data<<'\n';
		traverse = traverse->next;
	}
}

void reversal(type *traverse = last)
{
	int len = length;
	for(int i=len ; i > 0 ; i--)
	{
		std::cout<<"Index "<<i<<" has value : "<<traverse->data<<'\n';
		traverse = traverse->prev;
	}
}

void search(int value)
{
	type *traverse = first;
	int len = length;
	bool flag = false;
	for(int i=0 ; i < len ; i++)
	{
		if(traverse->data == value)
		{
			std::cout<<"Index "<<i<<" has value "<<traverse->data<<'\n';
			traverse = traverse->next;
			flag = true;
			break;
		}
	}
	if(!flag)
	{
		std::cout<<"Value does not exist"<<'\n';
	}
}

void menu()
{
	std::cout<<"\n\nPress the index of the work to be performed : \n";
	std::cout<<"1.Insert at beginning\n";
        std::cout<<"2.Insert at end\n";
        std::cout<<"3.Insert at n-th position\n";
        std::cout<<"4.Delete from beginning\n";
        std::cout<<"5.Delete from end\n";
	std::cout<<"6.Delete from nth index\n";
        std::cout<<"7.Traverse from beginning\n";
        std::cout<<"8.Search\n";
        std::cout<<"9.Traverse from end\n";
        std::cout<<"10.Exit\n";
}

int main()
{
	int option = 0;
	last = first = NULL;
	int flag = 0;
	string ch;
	int data;
	do
	{
		menu();
		std::cin>>option;
		switch(option)
		{
			case 1: std::cout<<"\nEnter the value to be inserted\n";
				std::cin>>data;
				insertAtBeg(data);
				std::cout<<"\nValue is inserted\n";
				break;
			case 2: std::cout<<"\nEnter the value to be inserted :\n";
				std::cin>>data;
				insertAtEnd(data);
				std::cout<<"\nValue is inserted\n";
				break;
			case 3: std::cout<<"\nEnter the value to be inserted\n";
				std::cin>>data;
				insertByIndex(data);
				std::cout<<"\nValue is Inserted\n";
				break;
			case 4: deleteFromBeg();
				std::cout<<"\nValue is deleted\n";
				break;
			case 5: deleteFromEnd();
				std::cout<<"Value is deleted\n";
				break;
			case 6: int index;
				std::cout<<"\n\t\t To Delete First Value Index : 1\n";
				std::cout<<"Enter the index to delete from list\n";
				std::cin>>index;
				deleteByIndex(index);
				break;
			case 7: traversal();
				break;
			case 8: std::cout<<"Enter the value to search";
				int data;
				std::cin>>data;
				search(data);
				break;
			case 9: reversal();
				break;
			case 10:flag=1; 
				break;
			default:std::cout<<"Invalid option";
		}
		if(flag)
		{
			ch = "n";
		}
		else
		{
			std::cout<<"do you want to continue Y/N";
			std::cin>>ch;
		}
	}while(ch == "Y" || ch =="y");
	return 0;
}