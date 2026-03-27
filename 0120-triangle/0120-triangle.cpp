class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> t = triangle;

        for(int row = n-2; row >= 0; row--){
            for(int col =0; col <= row; col++){
                t[row][col] = t[row][col] + min(t[row+1][col],
                t[row+1][min(col+1, (int)triangle[row+1].size()-1)]);
            }
        }
        return t[0][0];

    }
};