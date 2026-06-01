class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col, int n){

        for(int i =0; i < n; i++){
            if(board[row][i] == 'Q') return false;
        }

        for(int j = 0; j < n; j++){
            if(board[j][col] == 'Q') return false;
        }

        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }

        for(int i = row, j = col; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }
    void solve(int row, vector<vector<string>> &res, vector<string> &board, int n){
        if(row == n){
            res.push_back(board);
            return;
        }

        for(int j = 0; j < n; j++){
            if(isSafe(board, row, j, n)){
                board[row][j] = 'Q';
                solve(row+1, res, board, n);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        solve(0, res, board, n);
        return res;
    }
};