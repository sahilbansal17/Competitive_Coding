#include <bits/stdc++.h>
using namespace std;

const int BITS = 32;
struct trie_node {
    trie_node *left;
    trie_node *right;
};

void trie_insert(trie_node *node, int number) {
    for (int bit = BITS - 1; bit >= 0; bit --) {
        int current_bit = (number >> bit) & 1;
        if (current_bit == 1) {
            if (node->right == NULL) {
                node->right = new trie_node();
            }
            node = node->right;
        }
        else {
            if (node->left == NULL) {
                node->left = new trie_node();
            }
            node = node->left;
        }
    }
}

int get_min(trie_node *node, int current) {
    int value = 0;
    for (int bit = BITS - 1; bit >= 0; bit --) {
        int current_bit = (current >> bit) & 1;
        if (current_bit == 1) {
            if (node->right != NULL) {
                node = node->right;
            }
            else {
                // 1^0 = 1
                node = node->left;
                value ^= (1 << bit); // value += 2^bit 
            }
        }
        else {
            if (node->left != NULL) {
                node = node->left;
            }
            else {
                // 0^1 = 1
                node = node->right;
                value ^= (1 << bit); // value += 2^bit
            }
        }
    }
    return value;
}

int main() {
    int q; // number of queries
    cin >> q;
    
    int t, x, current = 0; // t: type, x: value, current: 

    trie_node *root = new trie_node();

    // insert 0 into the trie
    trie_insert(root, 0);

    while (q --) {
        cin >> t;
        if (t == 3) {
            cout << get_min(root, current) << endl;
        }
        else if (t == 1) {
            cin >> x;
            // add x
            trie_insert(root, x ^ current);
        }
        else if (t == 2) {
            cin >> x;
            current ^= x;
        }
    }
    return 0;
}
