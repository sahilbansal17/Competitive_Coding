#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CombinationIterator {
private:
    vector<string> res;
    int idx = 0;
    void solve(int id, int tot, string cur, string& inp, int k) {
        if (cur.length() == k) {
            res.push_back(cur);
            return;
        }
        if (id == tot) {
            return;
        }
        // take the current character
        solve(id + 1, tot, cur + inp[id], inp, k);
        // don't take
        solve(id + 1, tot, cur, inp, k);
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        int n = characters.length();
        solve(0, n, "", characters, combinationLength);
    }
    
    string next() {
        return res[idx++];
    }
    
    bool hasNext() {
        return idx < res.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main () {
    CombinationIterator* obj = new CombinationIterator("abcd", 2);
    while (obj->hasNext()) {
        cout << obj->next() << endl;
    }
    return 0;
}