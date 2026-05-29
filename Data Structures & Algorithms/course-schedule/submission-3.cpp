class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto &p: prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        // vector<bool> visited(numCourses, false)

        vector<int> indegree(numCourses);

        for(int i=0;i<numCourses;i++){
            for(int &v: adj[i]){
                indegree[v]++;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);

            for(int &v: adj[u]){
                if(--indegree[v]==0){
                    q.push(v);
                }
            }
        }

        return (ans.size() == numCourses);
    }
};
