class Solution {
public: 

    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col]=1;

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        for(int i =0; i <4; i++){
            int nrow = row+ delRow[i];
            int ncol = col + delCol[i];

            if(nrow>=0 && nrow< n && ncol >=0 && ncol < m && grid[nrow][ncol] ==1 &&
            vis[nrow][ncol]==0){
                dfs(nrow, ncol, grid, vis);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        int srow =0, erow= n-1, scol = 0, ecol =m-1;

        for(int i =scol; i <= ecol; i++){
            if(grid[srow][i] == 1 && vis[srow][i] == 0){
                dfs(srow, i, grid, vis);
            }
        }

        for(int i =srow+1; i <= erow; i++){
            if(grid[i][ecol] == 1 && vis[i][ecol] == 0){
                dfs(i, ecol, grid, vis);
            }
        }

        for(int i =ecol-1; i >= scol; i--){
            if(grid[erow][i] == 1 && vis[erow][i] == 0){
                dfs(erow, i, grid, vis);
            }
        }

        for(int i =erow-1; i >= srow+1; i--){
            if(grid[i][scol] == 1 && vis[i][scol] == 0){
                dfs(i, scol, grid, vis);
            }
        }

        int lands =0;
        for(int i =0; i <n; i++){
            for(int j =0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    lands++;
                }
            }
        }
        return lands;
    }
};