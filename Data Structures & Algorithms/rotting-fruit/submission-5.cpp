class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> que;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) que.push({i, j});
                else if(grid[i][j]==1) fresh++;
                else continue;
            }
        }

        int minutes = 0;

        while(!que.empty() && fresh>0){
            int size = que.size();

            while(size--){
                auto &p = que.front();
                que.pop();

                vector<pair<int,int>> dir = {
                    {0,1},{0,-1},{-1,0},{1,0}
                };

                for(auto &d: dir){
                    int nx = p.first+d.first;
                    int ny = p.second+d.second;

                    if(nx>=0 && nx<n && ny>=0 && ny<m &&
                     grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        fresh--;
                        que.push({nx, ny});
                    }
                }
            }
            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
