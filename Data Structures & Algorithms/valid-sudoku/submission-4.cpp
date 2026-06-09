class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //rows checking
        for(int i=0;i<board.size();i++){
            vector<int> freq(10,0);
            
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '.') continue;
                else {
                    int val = board[i][j] - '0';
                    if(freq[val] >= 1) return false;
                    freq[val]++;
                }
            }
        }
        //cols checking
        for(int i=0;i<board[0].size();i++){
            vector<int> freq(10,0);
            
            for(int j=0;j<board.size();j++){
                if(board[j][i] == '.') continue;
                else {
                    int val = board[j][i] - '0';
                    if(freq[val] >= 1) return false;
                    freq[val]++;
                }
            }
        }

        for(int row=0;row<9;row+=3){
            for(int col=0;col<9;col+=3){

                vector<int> freq(10,0);

                for(int i=row; i<row+3;i++){
                    for(int j=col; j<col+3;j++){
                        if(board[i][j] == '.') continue;

                        else{
                            int val = board[i][j] - '0';
                            if(freq[val]>=1) return false;
                            freq[val]++;
                        }
                    }
                }
            }
        }
        return true;
    }
};
