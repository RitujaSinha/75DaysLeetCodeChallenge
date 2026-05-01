class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i){
        if(i >= nums.size()) return 0;

        if(t[i] != -1) return t[i];

        int robb = nums[i] + solve(nums, i+2);
        int skip = solve(nums, i+1);

        return t[i] = max(skip, robb);
    }
    int rob(vector<int>& nums) {
        memset(t, -1, sizeof(t));

        return solve(nums, 0);
    }
};