class Solution {
public:
    bool bfs(int source , int destination , vector<int> adj[] , vector<int> &vis){
        queue<int> q;
        q.push(source);
        vis[source] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node == destination){
                return true;
            }
            for(int neigh : adj[node]){
                if(!vis[neigh]){
                    vis[neigh] = 1;
                    q.push(neigh);
                }
            }
        }
        return false;



    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(auto edge :  edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<int> vis(n , 0);
        return bfs(source , destination , adj , vis);


        
    }
};