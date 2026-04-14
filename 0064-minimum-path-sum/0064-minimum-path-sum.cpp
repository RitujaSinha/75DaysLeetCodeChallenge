class Solution {
public:     
    int solve(vector<vector<int>>& grid, int m , int n, int i, int j, vector<vector<int>> &t){
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }

        if(t[i][j] != -1) return t[i][j];

        if(i == m-1){
            return t[i][j]= grid[i][j] + solve(grid, m, n, i, j+1, t);
        } else if(j == n-1){
            return t[i][j]= grid[i][j] + solve(grid, m, n, i+1, j, t);
        } else{
            return t[i][j] =grid[i][j] + min(solve(grid, m, n, i+1, j, t), solve(grid, m, n, i, j+1, t));
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> t(m, vector<int> (n, -1));

        return solve(grid, m, n, 0, 0, t);
    }
};