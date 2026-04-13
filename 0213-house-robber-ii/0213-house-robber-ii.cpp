class Solution {
public:
    int t[101];
    int solve(vector<int> &nums, int n, int i){
        if(i >= n) return 0;

        if(t[i] != -1) return t[i];

        int take = nums[i] + solve(nums, n, i+2);
        int skip = solve(nums, n, i+1);

        return t[i] = max(take, skip); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];
        if(n==0) return 0;

        memset(t, -1, sizeof(t));
        int take0thHouse =  solve(nums, n-1, 0);

        memset(t, -1, sizeof(t));
        int notTake0thHouse = solve(nums, n, 1);

        return max(take0thHouse, notTake0thHouse);
    }
};