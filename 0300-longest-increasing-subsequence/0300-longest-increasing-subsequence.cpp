class Solution {
public:
    int solve(vector<int>& nums, int i, int P, vector<vector<int>> &dp){
        if(i >= nums.size()) return 0;

        if(P != -1 && dp[i][P] != -1) return dp[i][P];

        int take =0;
        if(P == -1 || nums[P] < nums[i]){
            take = 1+ solve(nums, i+1, i, dp);
        } 

        int skip = solve(nums, i+1, P, dp);

        if(P != -1){
            dp[i][P] = max(skip, take);
        }

        return  max(skip, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(nums, 0, -1, dp);
    }
};