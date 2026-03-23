class Solution {
public:
    map<pair<int, int>, int> mp;
    int solve(int idx, int currSum,int &count, vector<int>& nums, int target){
        if(idx >= nums.size()){
            if(currSum == target){
                return 1;
            } else{
                return 0;
            }
        }

        //if(currSum > target) return;
        if(mp.find({idx, currSum}) != mp.end()){
            return mp[{idx, currSum}];
        }


        long long plus = solve(idx+1,currSum-nums[idx], count, nums, target);

        long long minus = solve(idx+1,currSum+ nums[idx], count, nums, target);

        return mp[{idx, currSum}] = plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        mp.clear();

        int count =0;
        
        return solve(0,0 ,count, nums, target);
    }
};