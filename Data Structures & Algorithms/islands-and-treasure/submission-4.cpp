class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> que;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) {
                    que.push({i, j});
                }
            }
        }

        vector<pair<int,int>> dir = {
            {0,1},{0,-1},{-1,0},{1,0}
        };

        while(!que.empty()){
                auto& q = que.front();
                int i = q.first;
                int j = q.second;
                que.pop();
                for(auto &d:dir){
                    int ni = i+d.first;
                    int nj = j+d.second;

                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==INT_MAX){
                        grid[ni][nj]=grid[i][j]+1;
                        que.push({ni, nj});
                    }
                }
        }
    }
};
