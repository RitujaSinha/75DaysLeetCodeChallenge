class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();


        vector<int> ans;

        for(int i = 0; i < m; i++){
            int idx = -1, mini = INT_MAX;
            for(int j = 0; j < n; j++){
                if(mini > matrix[i][j]){
                    mini = matrix[i][j];
                    idx = j;
                }
            }

            int maxi = INT_MIN;
            for(int k = 0; k < m; k++){
                maxi = max(maxi, matrix[k][idx]);
            }

            if(mini == maxi){
                ans.push_back(mini);
            }
        }
        return ans;
    }
};