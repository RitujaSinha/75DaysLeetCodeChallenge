class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int row = 0; row < 9; row++){
            for(int col =0; col < 9; col++){
                if(board[row][col] == '.') continue;

                //horizontal
                for(int j = 0; j < 9; j++){
                    if(j != col && board[row][j] == board[row][col]){
                        return false;
                    }
                }

                //vertical
                for(int i = 0; i < 9; i++){
                    if(i != row && board[i][col] == board[row][col]){
                        return false;
                    }
                }

                int sr = (row/3)*3;
                int sc = (col/3)*3;

                for(int i =sr; i<=sr+2; i++){
                    for(int j = sc; j <= sc+2; j++){
                        if((i != row || j != col) && board[i][j] == board[row][col]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};