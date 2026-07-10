class Solution {
public:
    int m, n;
    bool checkWord(int row, int col,int idx, vector<vector<char>>& board, string word){

        if(idx == word.size()){
            return true;
        }

        char temp = board[row][col];
        board[row][col] = '#';

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i =0; i < 4; i++){

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >=0 && nrow < m && ncol >=0 && ncol < n){
                if(board[nrow][ncol] == word[idx]){
                    if(checkWord(nrow, ncol, idx+1, board, word)) return true;
                }
            }
        }

        board[row][col] = temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j =0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(checkWord(i, j,1, board, word)) return true;
                }
            }
        }
        return false;
    }
};