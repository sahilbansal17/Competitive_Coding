const int MAXI = 1e8;
class Solution {
private:
    map<pair<int, int>, int> cache;
    bool exists = false;
    int findMinPrice(int src, int dst, int K, vector<pair<int, int>> adj[]) {
        if (K == -1 && src != dst) {
            return MAXI;
        }
        if (src == dst) {
            exists = true;
            return 0;
        }
        if (cache[{src, K}]) {
            return cache[{src, K}];
        }
        int res = MAXI;
        for (auto next: adj[src]) {
            int node = next.first;
            int price = next.second;
            res = min(res, price + findMinPrice(node, dst, K - 1, adj));
        }
        return cache[{src, K}] = res;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int, int>> adj[n + 1];
        for (auto flight: flights) {
            int source = flight[0];
            int destination = flight[1];
            int price = flight[2];
            adj[source].push_back({destination, price});
        }
        int minPrice = findMinPrice(src, dst, K, adj);
        if (exists) {
            return minPrice;
        }
        return -1;
    }
};