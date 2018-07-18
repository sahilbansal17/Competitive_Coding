/*
 * There are two major functions in this program, partition and quickSort
 * It is responsible for choosing a pivot, and then
 * shift all elements lesser than the pivot to the left, and those greater than the
 * pivot to the right of the pivot.
 *
 * This is done recursively for all the partitions, i.e. the ones that are formed
 * to the left and the right of the pivot, until we end up with a sorted array.
 *
 * Any element can be chosen to be the pivot, but here, the last element
 * in the linked list is taken.
 *
 */


#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
};

void insertNode(ListNode **head, int data){
    //Insert at head
    ListNode *newNode = new ListNode();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

ListNode* findTail(ListNode *h){
    while(h != NULL && h->next != NULL)
        h=h->next;
    return h;
}

ListNode *partition(ListNode *head, ListNode *end, ListNode **newHead, ListNode **newTail){
    ListNode *pivot = end;
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *tail = pivot;

    while (curr != pivot){
        if (curr->data < pivot->data){
            if ((*newHead) == NULL)
                (*newHead) = curr;

            prev = curr;
            curr = curr->next;
        }
        else {
            if (prev != NULL)
                prev->next = curr->next;
            ListNode *t = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = t;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newTail) = tail;
    return pivot;
}

ListNode* quickSort(ListNode *head, ListNode *tail){
    if(head == NULL || head == tail) {
        return head;
    }

    ListNode *newHead = NULL, *newTail = NULL;
    ListNode *pivot = partition(head, tail, &newHead, &newTail);

    if (newHead != pivot){
        ListNode *t = newHead;
        while (t->next != pivot)
            t = t->next;
        t->next = NULL;

        newHead = quickSort(newHead, t);

        t = findTail(newHead);
        t->next =  pivot;
    }

    pivot->next = quickSort(pivot->next, newTail);
    return newHead;
}

int main(){
    cout << "Enter number of elements" << endl;
    int n;
    cin >> n;

    int i;

    cout << "Enter elements" << endl;
    int d;

    ListNode *head = NULL;

    for(i = 0; i < n; i ++){
        cin >> d;
        insertNode(&head, d);
    }

    head = quickSort(head, findTail(head));

    cout << "Sorted List" << endl;

    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }

    return 0;
}

/*
 * Sorting is done in place, so space complexity is O(1).
 * Time complexity is O(n*n) in worst case and O(n*Logn) in average case.
 * The worst case occurs when the linked list is already sorted.
 * 
 */
