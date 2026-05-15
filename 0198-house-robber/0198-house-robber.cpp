class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n+1, -1);

        dp[0] = 0; //no house -> no money
        dp[1] = nums[0]; //just rob the first

        for(int i = 2; i <= n; i++){

            int robb = nums[i-1] + dp[i-2];
            int skip = dp[i-1];

            dp[i] = max(robb, skip);
        }
        return dp[n];
    }
};