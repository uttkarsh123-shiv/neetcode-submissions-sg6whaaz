class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        queue<pair<int,int>> q1, q2;

        // Pacific
        for(int i = 0; i < n; i++){
            q1.push({i, 0});
            pac[i][0] = true;
        }
        for(int j = 0; j < m; j++){
            q1.push({0, j});
            pac[0][j] = true;
        }

        // Atlantic
        for(int i = 0; i < n; i++){
            q2.push({i, m-1});
            atl[i][m-1] = true;
        }
        for(int j = 0; j < m; j++){
            q2.push({n-1, j});
            atl[n-1][j] = true;
        }

        vector<pair<int,int>> dir = {
            {1,0},{-1,0},{0,1},{0,-1}
        };

        auto bfs = [&](queue<pair<int,int>>& q, vector<vector<bool>>& visited){
            while(!q.empty()){
                auto coord = q.front();
                q.pop();

                int i = coord.first;
                int j = coord.second;

                for(auto &d : dir){
                    int ni = i + d.first;
                    int nj = j + d.second;

                    if(ni>=0 && ni<n && nj>=0 && nj<m &&
                       !visited[ni][nj] &&
                       heights[ni][nj] >= heights[i][j]){

                        visited[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        };

        bfs(q1, pac);
        bfs(q2, atl);

        vector<vector<int>> res;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};