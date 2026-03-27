class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i){
        if(i >= nums.size()) return 0;

        if(t[i] != -1) return t[i];

        int steal = nums[i] + solve(nums, i+2);
        int skip = solve(nums, i+1);

        return t[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));

        if(n==1) return nums[0];

        if(n == 2) return max(nums[0], nums[1]);

        return solve(nums, 0);
    }
};