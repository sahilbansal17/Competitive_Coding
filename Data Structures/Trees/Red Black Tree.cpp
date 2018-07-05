//Name: Rishabh Garg
//E-mail: rishabhgarg25699@gmail.com
//TITLE:  TREE
/*
  Red Black Tree is a Binary Search Tree in which every node is colored eigther RED or BLACK.
                    Properties of Red Black Tree
  Property #1: Red - Black Tree must be a Binary Search Tree.
  Property #2: The ROOT node must colored BLACK.
  Property #3: The children of Red colored node must colored BLACK. (There should not be two consecutive RED nodes).
  Property #4: In all the paths of the tree there must be same number of BLACK colored nodes.
  Property #5: Every new node must inserted with RED color. 
  Property #6: Every leaf (e.i. NULL node) must colored BLACK.
*/

#include <stdio.h>
#include <stdlib.h>

#define STOP getchar()

struct node
{
	enum {black, red} color;
	int info;
	struct  node *lchild;
	struct  node *rchild;
	struct  node *parent;
};

int find(int item,struct node **loc);
void insert (int);
void insertBalance(struct node *nptr );
void del(int);
void delBalance(struct node *ptr);
void RotateLeft(struct node *ptr);
void RotateRight(struct node *ptr);
struct node *succ(struct node *ptr);
void inorder(struct node *ptr);
void display(struct node *ptr,int level);

struct node *root;         /* pointer for the root node */   
struct node *sentinel;     /*will be parent of root node and replace NULL everywhere*/
//Main function from where all functions will call
int main()
{
	int choice,num;
	
	sentinel = (struct node *) malloc(sizeof(struct node));
	sentinel->info = -1;
	sentinel->color = black;	
	root = sentinel;
	

	while(1)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Inorder Traversal\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
		 case 1:
			printf("Enter the number to be inserted : ");
			scanf("%d",&num);
			insert(num);
			break;
		 case 2:
			printf("Enter the number to be deleted : ");
			scanf("%d",&num);
			del(num);
			break;
		 case 3:
			inorder(root);
			break;
		 case 4:
			display(root,0);
			break;
		 case 5:
			exit(1);
		 default:
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
return 0;
}/*End of main()*/

int find(int item,struct node **loc)
{
	struct node *ptr;

	if(root==sentinel)/*Tree is empty*/
	{
		*loc=sentinel;
		return 0;
	}

	if(item==root->info)/*Item is at root*/
	{
		*loc=root;
		return 1;
	}

	/*Initialize ptr*/
	if(item < root->info)
		ptr=root->lchild;
	else
		ptr=root->rchild;

	while(ptr!=sentinel)
	{
		if(item == ptr->info)
		{       
			*loc=ptr;
			return 1;
		}
		if(item < ptr->info)
			ptr=ptr->lchild;
		else
			ptr=ptr->rchild;
	 }//End of while
	 *loc=sentinel;		/*Item not found*/
	 return 0;
}/*End of find()*/
/*
                 INSERTION IN RED BLACK TREE
  In a Red Black Tree, every new node must be inserted with color RED. 
  The insertion operation in Red Black Tree is similar to insertion operation in Binary Search Tree. 
  But it is inserted with a color property. After every insertion operation, we need to check all the properties of Red Black Tree. 
  If all the properties are satisfied then we go to next operation otherwise we need to perform following operation to make it Red Black Tree.
  1. Recolor
  2. Rotation followed by Recolor
  The insertion operation in Red Black tree is performed using following steps...

  Step 1: Check whether tree is Empty.
  Step 2: If tree is Empty then insert the newNode as Root node with color Black and exit from the operation.
  step 3: If tree is not Empty then insert the newNode as a leaf node with Red color.
  Step 4: If the parent of newNode is Black then exit from the operation.
  Step 5: If the parent of newNode is Red then check the color of parent node's sibling of newNode.
  Step 6: If it is Black or NULL node then make a suitable Rotation and Recolor it.
  Step 7: If it is Red colored node then perform Recolor and Recheck it. Repeat the same until tree becomes Red Black Tree.
*/
void insert (int ikey )
{
	struct node *tmp, *ptr, *par;
	
	par = sentinel;
	ptr = root;

	while( ptr != sentinel )
	{
		par = ptr;
		if( ikey < ptr->info )
			ptr = ptr->lchild;
		else if( ikey > ptr->info )
			ptr = ptr->rchild;
		else
		{
			printf("Duplicate\n");
			return;
		}
	}
	tmp = (struct node *) malloc(sizeof(struct node));
	tmp->info = ikey;
	tmp->lchild = sentinel;
	tmp->rchild = sentinel;
	tmp->color = red;
	tmp->parent = par;
	
	if(par==sentinel)
		root = tmp;
	else if(tmp ->info < par->info )
		par->lchild = tmp;
	else 
		par->rchild = tmp;
	
	printf("After insertion\n"); display(root,0); printf("\n\n");
	insertBalance(tmp);
	
}/*End of insert( )*/

void insertBalance(struct node *nptr )    //Function for checking the nodes are balance or not.
{                                          //If not then do balance because balancing nodes are     
	struct node *uncle, *par, *grandPar;   //compulasary for Red black Tree 
	
	while( nptr->parent->color == red )
	{
		par = nptr->parent;
		grandPar = par->parent;
		
		printf("N : %d,  P : %d,  G : %d, ",nptr->info, par->info, grandPar->info);		
		STOP;
		if( par == grandPar->lchild )
		{
			uncle = grandPar->rchild; 
			printf("U : %d\n", uncle->info);		
			printf("Parent of nptr is left child\n");
			
			if(uncle->color == red )/* Case L_1 */
			{
				printf("Case L_1  : Uncle is red, change colors\n");
				printf("Make node %d and Node %d black and make node %d red\n", par->info, uncle->info, grandPar->info);			
				par->color = black;
				uncle->color = black;
				grandPar->color =red;
				nptr = grandPar;
				display(root,0);printf("\n");
				STOP;
				printf("Now node N is %d\n", nptr->info);
			}
			else	/* uncle is black */
			{
				printf("Uncle is black\n\n");
				STOP;
				if( nptr == par->rchild)/* Case L_2a */
				{
					printf("Case L_2a  : Node N is right child\n");
					printf("Rotate left about node P : %d\n", par->info);
					RotateLeft(par);
					STOP;
					printf("After rotation, tree is :\n");  display(root,0); printf("\n");
					nptr = par;
					par = nptr->parent;
					STOP;
					printf("Transformed to Case L_2b\n");
					printf("Now N : %d,  P : %d,  G : %d, U : %d\n",nptr->info, par->info, grandPar->info, uncle->info);
					STOP;
				}
				printf("Case L_2b  : Node N is left child\n");/* Case L_2b */
				par->color = black;
				grandPar->color = red;
				printf("Rotate right about node G : %d\n", grandPar->info);
				STOP;
				RotateRight(grandPar);
				printf("After rotation, tree is :\n");  display(root,0);printf("\n");
				STOP;
			}
		}
		else 
		{
			if(par == grandPar->rchild )
			{
				uncle = grandPar->lchild;  
				printf("U : %d\n", uncle->info);		
				printf("Parent of nptr is right child\n");
				
				if(uncle->color == red )/* Case R_1 */
				{
					printf("Case R_1 : Uncle is red, change colors\n");
					printf("Make node %d and Node %d black and make node %d red\n", par->info, uncle->info, grandPar->info);			
					par->color = black;
					uncle->color = black;
					grandPar->color =red;
					nptr = grandPar;
					STOP;printf("\n");
					printf("Now node N is %d\n", nptr->info);
				}
				else	/*uncle is black */ 
				{
					printf("Uncle is black\n\n");
					STOP;
					if( nptr == par->lchild)/* Case R_2a */
					{
						printf("Case R_2a  : Node N is left child\n");
						printf("Rotate right about node P : %d\n", par->info);
						RotateRight(par);
						STOP;	
						printf("After rotation, tree is :");  display(root,0);printf("\n");
						nptr = par;
						par = nptr->parent;
						STOP;
						printf("Transformed to Case R_2b\n");
						printf("Now N : %d,  P : %d,  G : %d, U : %d\n",nptr->info, par->info, grandPar->info, uncle->info);
						STOP;
					}
					printf("Case R_2b  : Node N is right child\n");/* Case R_2b */
					par->color = black;
					grandPar->color = red;
					printf("Rotate left about node G : %d\n", grandPar->info);
					STOP;
					RotateLeft(grandPar);
					printf("After rotation, tree is :");  display(root,0);printf("\n");
					STOP;
				}
			}
		}
	}
	root->color = black;
	printf("After balancing, tree is :");  display(root,0);printf("\n");
}/*End of insertBalance()*/
/*
             DELETION IN RED BLACK TREE
In a Red Black Tree, the deletion operation is similar to deletion operation in BST. 
But after every deletion operation we need to check with the Red Black Tree properties. 
If any of the property is voilated then make suitable operation like Recolor or Rotaton & Recolor.
*/
void del(int item)
{
	struct node *child,*ptr,*successor;
    
	if( ! find(item, &ptr) )
	{
		printf("item not present \n");
		return;
	}

	if(ptr->lchild != sentinel || ptr->rchild != sentinel )
	{
		successor = succ(ptr);
		ptr->info = successor->info;
		ptr=successor;
	}
		
	if( ptr->lchild !=sentinel )
		child = ptr->lchild;
	else
		child = ptr->rchild;
	
	child->parent = ptr->parent;
	
	if(ptr->parent == sentinel)
		root=child;
	else if( ptr == ptr->parent->lchild )
		ptr->parent->lchild = child;
	else 
		ptr->parent->rchild = child;
	
	printf("Before balancing\n");display(root,0);printf("\n\n");
		
	if( child == root )
		child->color = black;
    else if( ptr->color == black )/*black node*/  
	{
		if( child != sentinel ) /*one child which is red*/
            child->color = black;
		else	/*no child*/
			delBalance(child);
	}
	printf("after balancing\n");display(root,0);printf("\n\n");
}/*End of del()*/
/* 
  After deletion a particular nodes, we have to balance remaining nodes
*/
void delBalance(struct node *nptr)
{
	struct node *sib;

	while( nptr!=root )
	{
		if( nptr == nptr->parent->lchild )
		{
			sib = nptr->parent->rchild;
			if( sib->color == red )/* Case L_1 */
			{
				printf("L_Case 1\n");
				sib->color = black;
				nptr->parent->color = red;
				RotateLeft(nptr->parent);
				sib = nptr->parent->rchild; /*new sibling which is black*/
				printf("\n");display(root,0);printf("\n");
			}
			if( sib->lchild->color == black  && sib->rchild->color == black )
			{
				sib->color=red;
				
				if(nptr->parent->color == red )/*Case L_2a*/
				{
					printf("L_Case 2a\n");
					nptr->parent->color = black;
					printf("\n");display(root,0);printf("\n");
					return;
				}
				else
				{
					printf("Case L_2b\n");
				    nptr=nptr->parent;	/*Case L_2b */
				}
				printf("\n");display(root,0);printf("\n");
			}
			else 
			{
				if(sib->rchild->color==black)  /*Case L_3a*/
				{
					printf("Case L_3a\n");
					sib->lchild->color=black;
					sib->color=red;
					RotateRight(sib);
					sib = nptr->parent->rchild;
					printf("\n");display(root,0);printf("\n");
				}
				
				printf("Case L_3b\n");
                sib->color = nptr->parent->color;  /*Case L_3b*/
				nptr->parent->color = black;
				sib->rchild->color = black;
				RotateLeft(nptr->parent);
				printf("\n");display(root,0);printf("\n");
				return;	
				
			}
		}
		else
		{
			sib = nptr->parent->lchild;
			if( sib->color == red )	/* Case R_1 */
			{
				printf("Case R_1\n");
				sib->color =black;
				nptr->parent->color = red;
				RotateRight(nptr->parent);
				sib = nptr->parent->lchild;
				printf("\n");display(root,0);printf("\n");
			}
			
			if( sib->rchild->color == black  && sib->lchild->color == black )
			{
				sib->color=red;
				if(nptr->parent->color == red )/* Case R_2a*/
				{
					printf("Case R_2a\n");
					nptr->parent->color = black;
					printf("\n");display(root,0);printf("\n");
					return;
				}
				else	/* Case R_2b*/
				{
					printf("Case R_2b\n");
					nptr=nptr->parent; 
				}
				printf("\n");display(root,0);printf("\n");
			}
            else 
			{
				if(sib->lchild->color==black)  /*Case R_3a*/
				{
					printf("Case R_3a\n");
					sib->rchild->color=black;
					sib->color=red;
					RotateLeft(sib);
					sib = nptr->parent->lchild;
					printf("\n");display(root,0);printf("\n");
				}
				
				printf("Case R_3b\n");		/*case R_3b*/
				sib->color = nptr->parent->color;
				nptr->parent->color = black;
				sib->lchild->color = black;
				RotateRight(nptr->parent);
				printf("\n");display(root,0);printf("\n");
				return;
			}
		}
	}
}/*end of delBalance*/
/*
  A rotation is a local operation in a search tree that preserves in-order traversal key ordering. We
  change the pointer structure trough rotation, which is a local operation in a search tree that preserves the
  binary-search-tree property. The figure illustrated below shows the two kinds of rotations: left rotations and
  right rotations. When we do a left rotation on a node x, we assume that its right child y is not NULL; x may
  be any node in the tree whose right child is not NULL. The left rotation “pivots” around the link from x to
  y. It makes y the new root of the subtree, with x as y’s left child and y’s left child as x’s right child.
*/
void RotateLeft(struct node *pptr)
{
	struct node *aptr;

	aptr = pptr->rchild;	/*aptr is right child of pptr*/
	pptr->rchild= aptr->lchild; 
	
	if(aptr->lchild !=sentinel)
        aptr->lchild->parent = pptr;
	
	aptr->parent = pptr->parent;
	
	if(pptr->parent == sentinel )
		root = aptr;
	else if( pptr == pptr->parent->lchild )	
		pptr->parent->lchild = aptr;
	else
		pptr->parent->rchild = aptr;
    aptr->lchild = pptr;		
	pptr->parent = aptr;
}/*End of RoatateLeft( )*/

void RotateRight(struct node *pptr)
{
	struct node *aptr;
	
	aptr = pptr->lchild;	
	pptr->lchild= aptr->rchild; 
	
	if(aptr->rchild !=sentinel )
        aptr->rchild->parent = pptr;

	aptr->parent = pptr->parent;

	if(pptr->parent == sentinel )
		root = aptr;
	else if( pptr == pptr->parent->rchild )	
		pptr->parent->rchild = aptr;
	else
		pptr->parent->lchild = aptr;

	aptr->rchild = pptr;		
	pptr->parent = aptr;
}/*End of RotateRight( )*/

struct node *succ(struct node *loc)
{
	struct node *ptr=loc->rchild;
	while(ptr->lchild!=sentinel)
	{
		ptr=ptr->lchild;
	}
	return ptr;
}

void inorder(struct node *ptr)
{
	if(ptr!=sentinel)
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->info);
		inorder(ptr->rchild);
	}
}/*End of inorder()*/

void display(struct node *ptr,int level)
{
	int i;
	if ( ptr!=sentinel )
	{
		display(ptr->rchild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->info);
		if(ptr->color==red)
			printf("^");
		else
			printf("*");
		display(ptr->lchild, level+1);
	}
}/*End of display()*/
/*
               TIME COMPLEXITY OF VARIOUS FUNCTION

        int find(int item,struct node **loc);          O(n)
        void insert (int);                             O(n)
        void insertBalance(struct node *nptr );        O(1)
        void del(int);                                 O(1)
        void delBalance(struct node *ptr);             O(1)
        void RotateLeft(struct node *ptr);             O(1)
        void RotateRight(struct node *ptr);            O(1)
        struct node *succ(struct node *ptr);           O(N)
        void inorder(struct node *ptr);                O(n^2)
        void display(struct node *ptr,int level);      O(n)
*/




