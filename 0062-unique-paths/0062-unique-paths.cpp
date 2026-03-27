class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> result(m, vector<int> (n));

        //fill first row
        for(int row = 0; row < n; row++){
            result[0][row] = 1;
        }

        //fill first col
        for(int col = 1; col < m; col++){
            result[col][0] = 1;
        }

        for(int i =1; i < m; i++){
            for(int j = 1; j < n; j++){
                result[i][j] = result[i-1][j] +  result[i][j-1];
            }
        }
        
        return result[m-1][n-1];
    }
};