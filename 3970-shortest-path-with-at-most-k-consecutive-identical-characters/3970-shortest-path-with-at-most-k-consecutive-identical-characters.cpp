class Solution {
    using T = tuple<int, int, int>;

public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        vector<vector<int>> ans(n, vector<int>(k + 1, INT_MAX));

        priority_queue<T, vector<T>, greater<T>> pq;

        ans[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, node, count] = pq.top();
            pq.pop();

            if (d != ans[node][count])
                continue;

            if (node == n - 1)
                return d;

            for (auto [v, wt] : adj[node]) {
                int newCount =
                    (labels[v] == labels[node]) ? count + 1 : 1;

                if (newCount > k)
                    continue;

                
                if (d > INT_MAX - wt)
                    continue;

                int newDist = d + wt;

                if (newDist < ans[v][newCount]) {
                    ans[v][newCount] = newDist;
                    pq.push({newDist, v, newCount});
                }
            }
        }

        return -1;
    }
};