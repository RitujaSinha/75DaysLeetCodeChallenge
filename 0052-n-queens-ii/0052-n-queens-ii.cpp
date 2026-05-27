class Solution {
public:
     bool isSafe(vector<string>&board, int n, int col, int row){
        
        for(int j = 0; j < n; j++){
            if(board[row][j] == 'Q') return false;
        }

        for(int i = 0; i < n; i++){
            if(board[i][col] == 'Q') return false;
        }

        for(int i= row, j =col; i>=0 &&j>=0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }

        for(int i= row, j =col; i>=0 && j< n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;

    }   
    void nQueens(int row, vector<string>&board, set<vector<string>> &ans, int n){
        if(row == n){
            ans.insert(board);
            return;
        }

        for(int j =0; j < n; j++){
            if(isSafe(board, n, j, row)){
                board[row][j] = 'Q';
                nQueens(row+1, board, ans, n);
                board[row][j] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        set<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        nQueens(0, board, ans, n);
        return ans.size();

    }
};