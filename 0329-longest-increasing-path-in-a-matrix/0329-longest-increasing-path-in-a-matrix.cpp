class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>> &t){
        int m =matrix.size();
        int n = matrix[0].size();

        if(t[row][col] != -1) return t[row][col];

        int ans =1;
        int curr = matrix[row][col];

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && curr < matrix[nrow][ncol]){
                ans= max(ans, 1+dfs(nrow, ncol, matrix, t));
            }
        }

        return t[row][col]= ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m =matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> t(m, vector<int> (n, -1));

        int ans = 1;
        for(int i =0; i < m; i++){
            for(int j =0; j < n; j++){
               ans = max(ans, dfs(i, j, matrix, t));
            }
        }
        return ans;
    }
};