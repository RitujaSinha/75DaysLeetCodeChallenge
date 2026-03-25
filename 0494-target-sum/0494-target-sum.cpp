class Solution {
public:
    void solve(vector<int>& nums, int target, int i, int currSum, int &count){
        if(i >= nums.size()){
        if(currSum == target){
            count +=1;
        }
            return;
        }

        // if(currSum > target) return; // cannot have this condition because minus is also there 

        solve(nums, target, i+1, currSum + nums[i], count);
        solve(nums, target, i+1, currSum - nums[i], count);

        return;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count =0;

        solve(nums, target, 0, 0, count);
        return count;
    }
};