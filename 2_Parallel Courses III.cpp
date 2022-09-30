Solution 1. Topological Sort (BFS)
A node's distance is its time plus the maximum distance of all predecessor nodes. We can calculate the distances via a topological sort. The answer is the maximum distance.

// OJ: https://leetcode.com/problems/parallel-courses-iii/
// Author: github.com/lzl124631x
// Time: O(N + E)
// Space: O(N + E)
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& E, vector<int>& T) {
        vector<vector<int>> G(n);
        vector<int> indegree(n), dist(n);
        for (auto &e : E) { // build graph and count indegrees
            G[e[0] - 1].push_back(e[1] - 1);
            indegree[e[1] - 1]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) { // enqueue nodes with 0 indegree.
                q.push(i);
                dist[i] = T[i]; // source nodes' distance is their corresponding time
            } 
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int v : G[u]) {
                dist[v] = max(dist[u] + T[v], dist[v]); // update the distance of node `v` using the maximum distance of predecessor nodes.
                if (--indegree[v] == 0) q.push(v); // enqueue node `v` when its indegree drops to 0
            }
        }
        return *max_element(begin(dist), end(dist)); // the answer is the maximum distance.
    }
};
Solution 2. DFS + Memo (Post-order Traversal)
// OJ: https://leetcode.com/problems/parallel-courses-iii/
// Author: github.com/lzl124631x
// Time: O(N + E)
// Space: O(N + E)
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& E, vector<int>& T) {
        vector<vector<int>> G(n);
        vector<int> dist(n);
        for (auto &e : E) G[e[1] - 1].push_back(e[0] - 1);
        function<int(int)> dfs = [&](int u) {
            if (dist[u]) return dist[u];
            int mx = 0;
            for (int v : G[u]) mx = max(mx, dfs(v));
            return dist[u] = mx + T[u];
        };
        for (int i = 0; i < n; ++i) dfs(i);
        return *max_element(begin(dist), end(dist));
    }
};