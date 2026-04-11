class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>> &vis){
        int n = board.size();
        int m = board[0].size();

        vis[row][col] = 1;

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        for(int i =0; i < 4; i++){
            int nrow =row +delRow[i];
            int ncol =col+delCol[i];

            if(nrow>=0 && nrow<n && ncol >=0 && ncol < m && vis[nrow][ncol] == 0
            && board[nrow][ncol]=='O'){
                dfs(nrow, ncol, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int> (m , 0));

        int srow =0, erow = n-1, scol =0, ecol =m-1;
        //upper boundary
        for(int i =scol; i <= ecol; i++){
            if(board[srow][i] == 'O' && vis[srow][i] == 0){
                dfs(srow, i, board, vis);
            }
        }

        //right boundary
        for(int i= srow+1; i <= erow; i++){
            if(board[i][ecol] == 'O' && vis[i][ecol] == 0){
                dfs(i, ecol, board, vis);
            }
        }

        //bottom boundary
        for(int i = ecol-1; i>= scol; i--){
            if(board[erow][i] == 'O' && vis[erow][i] == 0){
                dfs(erow, i, board, vis);
            }
        }

        //down boundary
        for(int i= erow-1; i >= srow+1; i--){
            if(board[i][scol] == 'O' && vis[i][scol] == 0){
                dfs(i, scol, board, vis);
            }
        }


        for(int i =0; i < n; i++){
            for(int j =0; j < m; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};