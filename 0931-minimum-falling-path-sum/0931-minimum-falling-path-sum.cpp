class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> t = matrix;

        for(int row = n-2; row >=0; row--){
            for(int col = 0 ;col < n; col++){
                t[row][col] = t[row][col] + min({t[row+1][max(col-1, 0)],
                t[row+1][col], 
                t[row+1][min(col+1, (int)t[row+1].size()-1)]});
            }
        }
        return *min_element(t[0].begin(), t[0].end());
    }
};