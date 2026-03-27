class Solution {
public:
    map<pair<int, int>, int> mp;
    int solve(vector<int>& nums, int target, int i, int sum){
        if(i>= nums.size()){
            if(sum == target) return 1;
            else return 0;
        }

        if(mp.find({i, sum}) != mp.end()) return mp[{i, sum}];

        int p = solve(nums, target, i+1, sum + nums[i]);
        int m = solve(nums, target, i+1, sum - nums[i]);

        return mp[{i, sum}] =p+m;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        mp.clear();
        int n = nums.size();

        return solve(nums, target, 0, 0);
    }
};