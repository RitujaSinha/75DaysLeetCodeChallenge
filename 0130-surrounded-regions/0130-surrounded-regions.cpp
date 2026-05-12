class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
        int m = board.size();
        int n = board[0].size();

        vis[row][col] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol] == 'O'
            && !vis[nrow][ncol]){
                dfs(nrow, ncol, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m , vector<int> (n, 0));

        for(int i = 0; i < n; i++){//upper-bottom
            if(board[0][i] == 'O' && !vis[0][i]){
                dfs(0, i, board, vis);
            }

            if(board[m-1][i] == 'O' && !vis[m-1][i]){
                dfs(m-1, i, board, vis);
            }
        }

        for(int j = 0; j < m; j++){
            if(board[j][0] == 'O' && !vis[j][0]){
                dfs(j, 0, board, vis);
            }

            if(board[j][n-1] == 'O' && !vis[j][n-1]){
                dfs(j, n-1, board, vis);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};