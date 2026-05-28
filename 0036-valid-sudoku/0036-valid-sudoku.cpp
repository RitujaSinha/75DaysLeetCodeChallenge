class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i < m; i++){
            for(int j =0; j < n; j++){
                if(board[i][j] == '.') continue;


                for(int col = 0; col< n; col++){
                    if(col != j && board[i][col] == board[i][j]) return false;
                }

                for(int row = 0; row < m; row++){
                    if(row != i && board[row][j] == board[i][j]) return false;
                }

                int sr = (i/3)*3;
                int sc = (j/3)*3;

                for(int row = sr; row < sr+3; row++){
                    for(int col = sc; col < sc+3; col++){
                        if((row != i || col != j) && board[row][col] == board[i][j]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};