// A C++ solution to the problem: https://www.hackerrank.com/challenges/ctci-linked-list-cycle/problem
// Complexity: O(n)

/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head==NULL)
        return false;
    Node *p1, *p2;
    p1 = head;
    p2 = head;
    while(1){
        if(p2->next==NULL || (p2->next)->next==NULL){
            return false;
        }
        p1 = p1->next;
        p2 = (p2->next)->next;
        if(p1 == p2){
            return true;
        }
    }
    return false;
}
