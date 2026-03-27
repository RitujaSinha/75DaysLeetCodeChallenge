class Solution {
public:
    map<pair<int, int>, int> mp;
    bool solve(vector<int>& nums, int k, int i){
        if(k ==0) return true;

        if(i >= nums.size()) return false;

        if(mp.find({i, k}) != mp.end()) return mp[{i, k}];

        bool take = solve(nums, k-nums[i], i+1);
        bool not_take =  solve(nums, k, i+1);

        return  mp[{i, k}] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        mp.clear();
        
        int S = accumulate(nums.begin(), nums.end(), 0);

        if(S % 2 != 0) return false;

        return solve(nums, S/2, 0);
    }
};