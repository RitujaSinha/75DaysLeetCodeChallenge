class Solution {
public:
    int solve(int i, int P, vector<int>& nums, vector<vector<int>> &dp){
        if(i >= nums.size()){
            return 0; //no element left
        }

        if(dp[i][P+1] != -1){
            return dp[i][P+1];
        }

        int take = 0;
        if(P == -1 || nums[i] > nums[P]){
            take = 1 + solve(i+1, i, nums, dp);
        }

        int skip = solve(i+1, P, nums, dp);

        return dp[i][P+1] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int> (n+1, -1));

        return solve(0, -1, nums, dp);
    }
};