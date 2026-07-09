class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> ans(n, vector<int> (n, 0));

        int k =0;
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j < n; j++){
                ans[j][k] = matrix[i][j];
            }
            k++;
        }
        
        for(int i =0; i < n; i++){
            for(int j =0; j < n; j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};