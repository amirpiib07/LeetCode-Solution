class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);

        for(auto &it: prerequisites){
            int u = it[1];
            int v = it[0];
            graph[u].push_back(v);
        }
        vector<int> indegree(n);
        for(int v = 0; v < n; v++){
            for(auto &it : graph[v]){
                    indegree[it]++;
            }
        }
        queue<int> q;
        for(int idx = 0; idx<n ; idx++){
            if(indegree[idx] == 0) q.push(idx);
        }
        vector<int> result;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            result.push_back(node);
            for(auto &it: graph[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        return result.size() == n;
    }
};