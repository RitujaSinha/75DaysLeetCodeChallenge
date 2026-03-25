class Solution {
public:
    int t[201][20001];
    bool solve(vector<int>& nums, int idx, int x){
        if(x==0) return true;

        if(idx >= nums.size()) return false;

        if(t[idx][x] != -1) return t[idx][x];

        bool take = false;
        if(nums[idx] <= x){
            take = solve(nums, idx+1, x-nums[idx]);
        }

        bool not_take = solve(nums, idx+1, x);

        return t[idx][x] = take || not_take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int S = accumulate(nums.begin(), nums.end(),0);
        int x = S/2;

        if(S % 2 != 0) return false;

        memset(t, -1, sizeof(t));

        return solve(nums, 0, x);
    }
};