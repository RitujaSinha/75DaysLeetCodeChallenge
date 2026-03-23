class Solution {
public:
    void solve(int idx, int currSum,int &count, vector<int>& nums, int target){
        if(idx >= nums.size()){
            if(currSum == target){
                count+=1;
            }
            return;
        }

        //if(currSum > target) return;

        solve(idx+1,currSum-nums[idx], count, nums, target);

        solve(idx+1,currSum+ nums[idx], count, nums, target);

        return;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int count =0;

        solve(0,0 ,count, nums, target);

        return count;
    }
};