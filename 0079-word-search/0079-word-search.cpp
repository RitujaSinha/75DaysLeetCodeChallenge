class Solution {
public:
    bool find(vector<vector<char>>& board,int i, int j,int idx, string &word){
        int m = board.size();
        int n = board[0].size();

        if(idx== word.size()-1){
            return true;
        }

        if(word[idx] != board[i][j]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '$';
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int dir = 0; dir < 4; dir++){
            int nrow = i + delrow[dir];
            int ncol = j + delcol[dir];

            if(nrow >=0 && ncol >=0 && nrow < m && ncol < n){
                if(board[nrow][ncol] == word[idx+1]){
                    if(find(board, nrow, ncol, idx+1, word)) return true;
                }
            }
        } 

        board[i][j] = temp; 
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();


        for(int i =0; i < m; i++){
            for(int j =0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(find(board, i, j,0, word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};