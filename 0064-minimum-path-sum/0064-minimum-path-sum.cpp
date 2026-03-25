class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m, vector<int> (n));

        result[0][0] = grid[0][0];

        //filling 1st row 
        for(int row = 1; row < n; row++){
            result[0][row] = grid[0][row] + result[0][row-1]; 
        }   


        //filling 1st col
        for(int col = 1; col < m; col++){
            result[col][0] = grid[col][0] + result[col-1][0]; 
        }

        for(int i =1; i < m; i++){
            for(int j =1; j < n; j++){
                result[i][j] = grid[i][j] + min(result[i-1][j], result[i][j-1]);
            }
        }
        return result[m-1][n-1];
    }
};