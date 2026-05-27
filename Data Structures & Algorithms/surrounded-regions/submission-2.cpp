class Solution {
public:
    void helper(vector<vector<char>>& board, int i, int j){
      if(
        i < 0 || i >= board.size() ||
        j < 0 || j >= board[0].size() ||
        board[i][j] == 'X' ||
        board[i][j] == 'S'
    ){
        return;
    }
    
    board[i][j]='S';

    vector<pair<int,int>> direction = {
        {0,1},{0,-1},{1,0},{-1,0}
    };

    for(auto &dir: direction){
        int ni = i+dir.first;
        int nj = j+dir.second;

        helper(board, ni, nj);
    }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
    
        for(int j=0;j<m;j++){
            if(board[0][j] == 'O') 
            helper(board, 0, j);
        }
        for(int j=0;j<m;j++){
            if(board[n-1][j] == 'O') 
            helper(board, n-1, j);
        }
        for(int i=1;i<n-1;i++){
            if(board[i][0] == 'O') 
            helper(board, i, 0);
        } 
        for(int i=1;i<n-1;i++){
            if(board[i][m-1] == 'O') 
            helper(board, i, m-1);
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O')  board[i][j]='X';
                if(board[i][j] == 'S') board[i][j]='O';
            }
        }

        // return board;

    }
};
