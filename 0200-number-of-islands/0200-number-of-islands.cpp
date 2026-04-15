class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        // vis[row][col] = 1;
        grid[row][col] = '0'; //Modified the input 

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i =0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < m && ncol >=0 && ncol < n && grid[nrow][ncol]=='1'){
                dfs(nrow, ncol, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>> vis(m, vector<int> (n, 0));

        int count =0;
        for(int i =0; i < m; i++){
            for(int j =0; j < n; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};