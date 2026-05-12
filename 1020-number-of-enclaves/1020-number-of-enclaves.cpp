class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int m = grid.size();
        int n = grid[0].size();

        vis[row][col] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && grid[nrow][ncol] == 1
            && !vis[nrow][ncol]){
                dfs(nrow, ncol, grid, vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));
        
        //upper-bottom
        for(int i = 0; i < n; i++){
            if(grid[0][i] == 1 && !vis[0][i]){
                dfs(0, i, grid, vis);
            }

            if(grid[m-1][i] && !vis[m-1][i]){
                dfs(m-1, i, grid, vis);
            }
        }

        //left-right
        for(int j = 0; j < m; j++){
            if(grid[j][0] == 1 && !vis[j][0]){
                dfs(j, 0, grid, vis);
            }

            if(grid[j][n-1] && !vis[j][n-1]){
                dfs(j, n-1, grid, vis);
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};