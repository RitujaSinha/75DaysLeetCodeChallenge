class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> result(n, vector<int> (n, 0));


        int num = n-1;
        for(int i = 0; i < n; i++){
            for(int j =0; j < n; j++){
                result[j][num] = matrix[i][j];
            }
            num--;
        }
        for(int i =0; i < n; i++){
            for(int j =0; j < n; j++){
                matrix[i][j] = result[i][j];
            }
        }
    }
};