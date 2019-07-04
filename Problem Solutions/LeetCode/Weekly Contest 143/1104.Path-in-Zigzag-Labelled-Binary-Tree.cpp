class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int n = floor(log2(1.0*label));
        vector <int> res;
        int p = pow(2, n);
        res.push_back(label);
        while (label > 1) {
            label /= 2;
            int diff = p - label - 1;
            p/= 2;
            label = p + diff;
            res.push_back(label);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};