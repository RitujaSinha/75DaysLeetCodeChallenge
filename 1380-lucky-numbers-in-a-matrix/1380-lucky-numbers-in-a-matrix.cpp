class Solution {
public:
    int findMin(vector<int> &nums){
        int n = nums.size();

        int mini = INT_MAX;
        int index = -1;
        for(int i = 0; i < n; i++){
            if(mini > nums[i]){
                mini = nums[i];
                index = i;
            }
        }
        return index;
    }
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> res;

        for(int i = 0; i < m; i++){
            int index = findMin(matrix[i]);
            int minEl = matrix[i][index];

            int maxEl = -1;
            for(int j = 0; j < m; j++){
                if(matrix[j][index] > maxEl){
                    maxEl = matrix[j][index];
                }
            }

            if(maxEl == minEl) res.push_back(minEl);
        }
        return res;
    }
};