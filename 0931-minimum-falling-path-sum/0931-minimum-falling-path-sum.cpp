class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> result = matrix;

        for(int row = n-2; row >= 0; row--){
            for(int col =0; col < n; col++){
                result[row][col] = matrix[row][col] + 
                std::min({result[row+1][std::max(col-1, 0)], 
                result[row+1][col], 
                result[row+1][std::min(col+1,(int)result[row+1].size()-1)]});
            }
        }
        return *min_element(result[0].begin(), result[0].end());
    }
};