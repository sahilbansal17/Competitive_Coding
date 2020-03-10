#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using Bulb = array<ull, 3>;

struct KDNode {
    KDNode* left;
    KDNode* middle;
    KDNode* right;
    ull subtreeCost; // including this node
    Bulb item;
};

KDNode* makeLeaf(Bulb& bulb) {
    KDNode* node = new KDNode();
    node->left = nullptr;
    node->middle = nullptr;
    node->right = nullptr;
    node->subtreeCost = bulb[2];
    node->item = bulb;
    return node;
}

KDNode* insert(KDNode* root, Bulb& bulb, ull depth = 0) {
    if (!root) {
        return makeLeaf(bulb);
    }
    ull dim = depth % 3;
    if (bulb[dim] < root->item[dim]) {
        root->left = insert(root->left, bulb, depth + 1);
    } else if (bulb[dim] == root->item[dim]) {
        root->middle = insert(root->middle, bulb, depth + 1);
    } else {
        root->right = insert(root->right, bulb, depth + 1);
    }
    root->subtreeCost += bulb[2];
    return root;
}

ull query(KDNode* root, ull min_b, ull max_h, ull max_c, ull depth, bool b_ok = false, bool h_ok = false, bool c_ok = false) {
    ull cnt = 0;
    if (!root) {
        return 0;
    }
    
    // first, check for current item
    
    if (b_ok && c_ok && h_ok) {
        return root->subtreeCost;
    }
    if (root->item[0] >= min_b & root->item[1] <= max_h & root->item[2] <= max_c) {
        cnt += root->item[2];
    }
    if (!root->left & !root->middle & !root->right) {
        return cnt;
    }
    
    ull dim = depth % 3;
    if (dim == 0) {
        if (root->item[0] < min_b) {
            cnt += query(root->right, min_b, max_h, max_c, depth + 1, b_ok, h_ok, c_ok);
        } else if (root->item[0] == min_b) {
            cnt += query(root->middle, min_b, max_h, max_c, depth + 1, true, h_ok, c_ok);
            cnt += query(root->right, min_b, max_h, max_c, depth + 1, true, h_ok, c_ok);
        } else {
            cnt += query(root->left, min_b, max_h, max_c, depth + 1, b_ok, h_ok, c_ok);
            cnt += query(root->middle, min_b, max_h, max_c, depth + 1, true, h_ok, c_ok);
            cnt += query(root->right, min_b, max_h, max_c, depth + 1, true, h_ok, c_ok);
        }
    } else if (dim == 1) {
        if (root->item[1] > max_h) {
            cnt += query(root->left, min_b, max_h, max_c, depth + 1, b_ok, h_ok, c_ok);
        } else if (root->item[1] == max_h) {
            cnt += query(root->middle, min_b, max_h, max_c, depth + 1, b_ok, true, c_ok);
            cnt += query(root->left, min_b, max_h, max_c, depth + 1, b_ok, true, c_ok);
        } else {
            cnt += query(root->left, min_b, max_h, max_c, depth + 1, b_ok, true, c_ok);
            cnt += query(root->middle, min_b, max_h, max_c, depth + 1, b_ok, true, c_ok);
            cnt += query(root->right, min_b, max_h, max_c, depth + 1, b_ok, h_ok, c_ok);
        }
    } else if (dim == 2) {
        if (root->item[2] > max_c) {
            cnt += query(root->left, min_b, max_h, max_c, depth + 1, b_ok, h_ok, c_ok);
        } else if (root->item[2] == max_c) {
            cnt += query(root->middle, min_b, max_h, max_c, depth + 1, b_ok, h_ok, true);
            cnt += query(root->left, min_b, max_h, max_c, depth + 1, b_ok, h_ok, true);
        } else {
            cnt += query(root->left, min_b, max_h, max_c, depth + 1, b_ok, h_ok, true);
            cnt += query(root->middle, min_b, max_h, max_c, depth + 1, b_ok, h_ok, true);
            cnt += query(root->right, min_b, max_h, max_c, depth + 1, b_ok, h_ok, c_ok);
        }
    }
    return cnt;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ull nt;
	cin >> nt;
	for (ull t = 0; t < nt; ++t) {
	    ull n, q;
	    cin >> n >> q;
	    KDNode* root = nullptr;
	    for (ull i = 0; i < n; ++i) {
	        ull b, h, c;
	        cin >> b >> h >> c;
	        Bulb bulb = {b,h,c};
	        root = insert(root, bulb);
	    }
	    
	    for (ull i = 0; i < q; ++i) {
	        ull min_b,max_h,max_c;
	        cin >> min_b >> max_h >> max_c;
	        ull cnt = 0;
	        cnt = query(root, min_b, max_h, max_c, 0);
	        // we need to count how many bulbs there are with b >= min_b, h <= max_h, c >= max_c
	        
	        cout << cnt;
	        if (i < q-1) {
	            cout << " ";
	        }
	    }
	    cout << "\n";
	}
	return 0;
}