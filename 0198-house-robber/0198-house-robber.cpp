class Solution {
public:
    int solve(int i, vector<int> &nums, vector<int> &dp){
        if(i >= nums.size()){
            return 0; //no house left
        }

        if(dp[i] != -1) return dp[i];

        int robb = nums[i] + solve(i+2, nums, dp);
        int skip = solve(i+1, nums, dp);

        return dp[i] = max(robb, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(0, nums, dp);
    }
};