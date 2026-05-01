class Solution {
public:
    int solve(vector<int>& nums, int i, int n, vector<int> &t){
        if(i >= n) return 0;

        if(t[i] != -1) return t[i];

        int robb = nums[i] + solve(nums, i+2, n, t);
        int skip = solve(nums, i+1, n, t);


        return t[i] = max(skip, robb);
    }
    int rob(vector<int>& nums) {
        int n =nums.size();

        if(n==1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp1(n, -1);
        int zeroth = solve(nums, 0, n-1, dp1);

        vector<int> dp2(n, -1);
        int first = solve(nums, 1, n, dp2);

        return max(first, zeroth);
    }
};