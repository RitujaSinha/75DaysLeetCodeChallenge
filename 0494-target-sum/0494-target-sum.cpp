class Solution {
public:
    map<pair<int, int>, int> mp;
    int solve(vector<int>& nums, int target, int i, int currSum){
        if(i == nums.size()){
        return currSum == target;
        }

        if(mp.find({i, currSum}) != mp.end()) return mp[{i, currSum}];

        int takePlus = solve(nums, target, i+1, currSum + nums[i]);
        int takeMinus = solve(nums, target, i+1, currSum - nums[i]);

        return mp[{i, currSum}] = takePlus+ takeMinus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        mp.clear();

        return solve(nums, target, 0, 0);
    }
};