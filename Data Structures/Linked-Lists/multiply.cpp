/* In this program, two numbers, denoted by two linked lists whose
 * nodes contain the digits, are multiplied. This is done by first
 * adding the digits to the tail of the linked list and then
 * extracting each digit from the head to make the complete number.
 *
 * The time complexity of this program is O(m*n) where m and n are
 * the number of digits in the respective numbers.
 *
 * Moreover, the insertion operations take O(n) time each, where n
 * is the number of nodes/digits to be inserted.
 *
 */

#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
};

void insertInList(ListNode **node, int data){

    ListNode *newNode = new ListNode();
    ListNode *last = *node;
    newNode->data = data;

    newNode->next = NULL;

    if(*node == NULL){
        *node = newNode;
        return;
    }

    while(last->next != NULL)
        last = last->next;

    last->next = newNode;
    return;
}

void multiply( ListNode* head1, ListNode *head2 ){

    int n1 = 0, n2 = 0;

    while( head1 != NULL ){
        n1 = n1*10 + head1->data;
        head1 = head1->next;
    }

    while( head2 != NULL ){
        n2 = n2*10 + head2->data;
        head2 = head2->next;

    }
    cout<<n1*n2;
}

int main(){
    int n1,n2;

    cout << "Enter number of digits in the first number" << endl;
    cin>>n1;

    cout << "Enter digits in the first number" << endl;

    ListNode *head1 = NULL;
    int val1;

    int i;

    for(i = 0; i < n1; i ++){
        cin>>val1;
        insertInList(&head1, val1);
    }

    cout << "Enter number of digits in the second number" << endl;
    cin>>n2;

    cout << "Enter digits in the second number" << endl;

    ListNode *head2 = NULL;
    int val2;

    for(i = 0; i < n2; i ++){
        cin>>val2;
        insertInList(&head2, val2);
    }

    multiply(head1, head2);
    return 0;
}
