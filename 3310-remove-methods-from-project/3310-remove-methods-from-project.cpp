class Solution {
public:
  void dfs (int node , vector<vector<int>>& graph , vector<bool>& vis){
    vis[node] = true;
    for(int nei : graph[node]){
        if(!vis[nei]){
            dfs(nei , graph , vis);
        }
    }
  }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        // graph bnya hai isma
        for (auto &edge : invocations) {
            graph[edge[0]].push_back(edge[1]);
        }
         vector<bool> vis(n, false);
         //graph call 
        dfs(k, graph, vis);
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans.push_back(i);
            }
        }

        return ans;

        
    }
};