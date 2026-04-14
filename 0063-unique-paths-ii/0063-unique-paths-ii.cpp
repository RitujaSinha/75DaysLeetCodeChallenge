class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> t(m, vector<int> (n, 1));

        //fill first row
        for(int col = 0; col < n; col++){
            if(col >= 1 && obstacleGrid[0][col-1] == 1){
                t[0][col] = 0;
                obstacleGrid[0][col] =1;
            } else if(obstacleGrid[0][col]==1){
                t[0][col] = 0;
            } else{
                t[0][col]=1;
            }
        }

        //fill first col
        for(int row = 1; row < m; row++){
           if(row >= 0 && obstacleGrid[row-1][0] == 1){
                t[row][0] = 0;
                obstacleGrid[row][0] = 1;
            }  else if(obstacleGrid[row][0] == 1){
                t[row][0] =0;
            } else{
                t[row][0] = 1;
            }
        }

        //fill remaining
        for(int i =1; i < m; i++){
            for(int j =1; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    t[i][j] = 0;
                } else{
                    t[i][j] = t[i-1][j] + t[i][j-1];
                }
            }
        }
        return t[m-1][n-1];
    }
};