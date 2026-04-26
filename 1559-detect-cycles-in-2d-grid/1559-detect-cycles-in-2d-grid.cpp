class Solution {
public:
    bool dfs(int row, int col, int parentRow, int parentCol, char ch, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int m = grid.size();
        int n = grid[0].size(); 

        vis[row][col] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i =0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol =  col + delcol[i];

            if(nrow >=0 && nrow < m && ncol >=0 && ncol < n && grid[nrow][ncol] == ch){
                if(vis[nrow][ncol] == 1 && nrow != parentRow && ncol != parentCol){
                    return true;
                } else{
                    if(!vis[nrow][ncol])
                    if(dfs(nrow, ncol, row, col, ch, grid, vis) == true) return true;
                }
            }
        }
        return false;   
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));

        for(int i =0; i < m; i++){
            for(int j =0; j < n; j++){
                if(!vis[i][j]){
                    if(dfs(i, j ,-1, -1, grid[i][j], grid, vis) == true) return true;
                }
            }
        }
        return false;
    }
};