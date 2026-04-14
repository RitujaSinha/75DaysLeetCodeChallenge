class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> t(m, vector<int> (n, 0));

        //filling first row
        for(int row =0; row < n; row++){
            t[0][row] =1;
        }

        //filling first col
         for(int col =1; col < m; col++){
            t[col][0] =1;
        }

        //fill remaning cells
        for(int i =1; i < m; i++){
            for(int j =1; j < n; j++){
                t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }
        return t[m-1][n-1];
    }
};