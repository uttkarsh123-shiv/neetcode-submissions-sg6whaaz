class Solution {
public:
    void dfs(int i, int j,vector<vector<int>>& grid, vector<vector<int>> &visited, int &area){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || visited[i][j]==1 || grid[i][j]==0){
            return;
        }
        visited[i][j] = 1;
        area++;

        dfs(i, j+1, grid, visited, area);
        dfs(i+1, j, grid, visited, area);
        dfs(i-1, j, grid, visited, area);
        dfs(i, j-1, grid, visited, area);
    
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int maxArea = 0;
        // int area=0;
        for(int i=0;i<n;i++){
                // area=0/;
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 || visited[i][j]) continue;
                    int area=0;
                    dfs(i, j, grid, visited, area);
            maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
