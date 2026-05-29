class Solution {
public:
    bool dfs(int node,int parent, vector<vector<int>>& adj, vector<bool> &visited){
        visited[node] = true;

        for(auto &v: adj[node]){
            if(visited[v] && v != parent) {
                return false;
            }

            if(!visited[v]){
                if(!dfs(v, node, adj, visited)){
                    return false;
                }
            }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // A graph to be a Tree must satisfy two conditions 
        // 1. Graph must not be in connected omponent (means there are 
        // many small grpahs that are connected)
        // 2. There must be no Cycle present at all
    
        vector<vector<int>> adj(n);

        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        int components = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                components++;

                if(components > 1) {
                    return false;
                }

                if(!dfs(i,-1, adj, visited)){
                    return false;
                }
            }
        }
        return true;
    }
};
