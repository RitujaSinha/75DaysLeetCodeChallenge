class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> t(m, vector<int> (n, 0));

        //fill first row
        for(int col = 0; col < n; col++){
            if(obstacleGrid[0][col] == 0){
                t[0][col] = 1;
            } else{
                break;
            }
        }

        //fill first col
        for(int row = 1; row < m; row++){
            if(obstacleGrid[row][0] == 0){
                t[row][0] = 1;
            } else{
                break;
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