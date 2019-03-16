/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <sstream>
#include <vector> 

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyRoot = new ListNode(0);
        ListNode* cur = dummyRoot;
        int sum = 0, carry = 0, val;
        while (l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + carry;
            if (sum >= 10) {
                val = sum % 10;
                carry = sum/10;
            }
            else {
                val = sum;
                carry = 0;
            }
            cur -> next = new ListNode(val);
            cur = cur -> next;

            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while (l1 != NULL) {
            sum = l1 -> val + carry;
            if (sum >= 10) {
                val = sum % 10;
                carry = sum/10;
            }
            else {
                val = sum;
                carry = 0;
            }
           
            cur -> next = new ListNode(val);
            cur = cur -> next;
            
            l1 = l1 -> next;
        }
        while (l2 != NULL) {
            sum = l2 -> val + carry;
            if (sum >= 10) {
                val = sum % 10;
                carry = sum/10;
            }
            else {
                val = sum;
                carry = 0;
            }
           
            cur -> next = new ListNode(val);
            cur = cur -> next;
            
            l2 = l2 -> next;
        }
        if (carry > 0) {
            cur -> next = new ListNode(carry);
        }
        cur = dummyRoot->next;
        delete dummyRoot;
        return cur;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}