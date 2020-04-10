class Solution {
private:
    bool cycleCheckDFS(int course, vector<int> adj[], vector<int>& visited) {
        visited[course] = 2; // being explored
        
        bool res = false;
        for (auto next: adj[course]) {
            if (visited[next] == 0) { // not visited
                res = res | cycleCheckDFS(next, adj, visited);
            } else if (visited[next] == 2) {
                // need to check whether next is not completely explored
                res = true; // because back-edge, leads to cycle
            }
        }
        visited[course] = 1; // completely explored
        return res;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // i->j: take course i before j
        // [[1, 0]]: 0 -> 1
        // directed graph
        
        // 0: 1
        // 1: 
        
        // construct the graph
        vector<int> adj[numCourses];
        for (auto prereq: prerequisites) {
            int pre = prereq[1];
            int post = prereq[0];
            // pre->post
            adj[pre].push_back(post);
        }
        
        bool cycleExists = false;
        vector<int> visited(numCourses, 0); // 3 states => 0, 1 or 2
        for (int course = 0; course < numCourses; ++course) {
            // visited vector
            if (!visited[course]) {
                cycleExists = cycleExists | cycleCheckDFS(course, adj, visited);
            }
        }
        
        return !cycleExists;
    }
};