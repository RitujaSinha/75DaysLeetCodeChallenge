class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int m = grid.size();
        int n = grid[0].size();

        vis[row][col] =1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i =0; i < 4; i++){

            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < m && ncol >=0 && ncol < n && grid[nrow][ncol] == 1
            && !vis[nrow][ncol]){
                dfs(nrow, ncol, grid, vis);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));

        //first row and first col
        for(int j =0; j < n; j++){

            if(!vis[0][j] && grid[0][j] == 1){
                dfs(0, j, grid, vis);
            }

            if(!vis[m-1][j] && grid[m-1][j] == 1){
                dfs(m-1, j, grid, vis);
            }
        }

        for(int i =0; i < m; i++){

            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i, 0,  grid, vis);
            }

            if(!vis[i][n-1] && grid[i][n-1] == 1){
                dfs(i, n-1, grid, vis);
            }
        }
        
        int lands = 0;
        for(int i =0; i < m; i++){
            for(int j =0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    lands++;
                }
            }
        }
        return lands;
    }
};