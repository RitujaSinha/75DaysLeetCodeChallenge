class Solution {
public:
    int t[101][101];
    int solve(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j){
        if(i == m-1 && j == n-1) return 1;

        if(i >= m || j >= n || obstacleGrid[i][j] == 1){
            return 0;
        }

        if(t[i][j] != -1) return t[i][j];

        int right = solve(obstacleGrid, m, n, i, j+1);
        int down = solve(obstacleGrid, m, n, i+1, j);

        return t[i][j] = right+down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1] == 1) return 0;
        if(obstacleGrid[0][0] == 1) return 0;

        memset(t, -1, sizeof(t));

        return solve(obstacleGrid,m, n, 0, 0);
    }
};