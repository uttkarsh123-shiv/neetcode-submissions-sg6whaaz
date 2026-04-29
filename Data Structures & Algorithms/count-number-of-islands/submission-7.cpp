class Solution {
public:
    void dfs(int i, int j, int &count, vector<vector<char>>& grid, vector<vector<int>>& visited){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || visited[i][j] == 1 || grid[i][j]=='0'){
            return;
        }
        visited[i][j] = 1;

        dfs(i+1, j, count, grid, visited);
        dfs(i-1, j, count, grid, visited);
        dfs(i, j-1, count, grid, visited);
        dfs(i, j+1, count, grid, visited);
    }


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0') continue;
                if(!visited[i][j]){
                    count++;
                    dfs(i, j, count, grid, visited);
                }
            }
        }

        return count;
    }
};
