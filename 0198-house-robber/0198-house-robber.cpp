class Solution {
public:
    map<pair<int, int>, int> mp;
    int solve(vector<int>& nums, int i, int maxSum){
        if(i >= nums.size()){
            return maxSum;
        }

        if(mp.find({i, maxSum}) != mp.end()) return mp[{i, maxSum}] ;

        int rob = solve(nums, i+2, maxSum + nums[i]);
        int skip = solve(nums, i+1, maxSum);

        return mp[{i, maxSum}] = max(rob, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        mp.clear();

        return solve(nums, 0, 0);
    }
};