class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows); // 5

        for(int i =0; i < numRows; i++){
            ans[i] = vector<int>(i+1, 1); // 0, 1, 2, 3, 4

            for(int j = 1; j < i; j++){
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }

        }
        return ans;
    }
};
// 0 1 2
// 1
// 1 1 ,,, i = 1
// 1 2 1 
// 1 3 3 1
// 1 4 6 4 1

// [i-1][j] + [i-1][j-1]
