class Solution {
public:
    bool solve(int i, vector<int> &nums, int x,  vector<vector<int>> &t){
        if(x == 0){
            return true;
        }
        if(i == nums.size()){
            return false;
        }

        if(t[i][x] != -1) return t[i][x];

        bool take = false;
        if(x >= nums[i]){
            take = solve(i+1, nums, x-nums[i], t);
        }

        bool notTake = solve(i+1, nums, x, t);

        return t[i][x] = (take || notTake);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> t(n, vector<int> (200001, -1));

        int s = accumulate(nums.begin(), nums.end(), 0);

        if(s % 2 !=0) return false;

        int x = s/2;

        // vector<vector<int>> t(n, vector<int> (20001, -1));

        return solve(0, nums, x, t);
    }
};