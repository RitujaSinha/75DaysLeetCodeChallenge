class Solution {
public:
    bool dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vis[row][col] = 1;

        bool closed= true;

        if(row <=0 || row >= m-1 || col <= 0 || col >= n-1) closed= false;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i =0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                if(grid[nrow][ncol] == 0 && !vis[nrow][ncol]){
                    if(dfs(nrow, ncol, vis, grid)== false)closed = false;
                }
            }
        }
        return closed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));

        int islands =0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    if(i== 0 || i == m-1 || j== 0 || j == n-1) continue;

                    if(dfs(i, j, vis, grid) == true) islands++;
                }
            }
        }
        return islands;
    }
};