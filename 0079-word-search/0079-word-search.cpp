class Solution {
public:
    bool find(vector<vector<char>>& board,int i, int j, int idx, string& word){
        int m = board.size();
        int n = board[0].size();

        if(i < 0 || j < 0 || i>= m || j >= n || board[i][j] == '$'){
            return false;
        }

        if(board[i][j] != word[idx]) return false;

         if(idx == word.size()-1){
            return true;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for(int dir =0; dir < 4; dir++){
            int nrow = i + delrow[dir];
            int ncol = j + delcol[dir];

            if(nrow >=0 && nrow < m && ncol >=0 && ncol < n){
                if(find(board, nrow, ncol, idx+1, word)) return true;
            }
        }
        board[i][j] = temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i <m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0] && find(board, i, j, 0, word)){ //pehle word ke char match hua to check krege 4 side
                    return true;
                }
            }
        }
        return false;
    }
};