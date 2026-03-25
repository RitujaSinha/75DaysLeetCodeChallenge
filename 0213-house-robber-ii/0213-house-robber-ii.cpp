class Solution {
public:
    int solve(vector<int>& nums, int i, int n, int maxSum, vector<vector<int>> &dp){
        if(i >= n ) return maxSum;

        if(dp[i][maxSum] != -1) return dp[i][maxSum];

        int rob = solve(nums, i+2, n, maxSum + nums[i], dp);
        int skip = solve(nums, i+1, n, maxSum, dp);

        return dp[i][maxSum]= max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        if(n==2) return max(nums[0], nums[1]);

        vector<vector<int>> t1(n+1, vector<int> (100001, -1));
        int robFirstHouse = solve(nums, 0, n-1, 0, t1);

        vector<vector<int>> t2(n+1, vector<int> (100001, -1));
        int skipFirstHouse = solve(nums, 1, n, 0, t2);

        return max(robFirstHouse, skipFirstHouse);
    }
};