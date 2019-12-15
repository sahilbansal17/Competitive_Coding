#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while (head) {
            if (head->val == 1) {
                res *= 2;
                res += 1;
            } else {
                res *= 2;
            }
            head = head->next;
        }
        return res;
    }
    void printList(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

int main () {
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    head->next = new ListNode(0);
    cur = cur->next;
    cur->next = new ListNode(1);

    Solution solver;
    cout << solver.getDecimalValue(head) << endl; // 5
    return 0;
}