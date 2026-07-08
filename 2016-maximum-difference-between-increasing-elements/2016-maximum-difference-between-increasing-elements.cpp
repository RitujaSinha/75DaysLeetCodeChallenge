class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();

        int mini = nums[0];
        int ans = -1;
        for(int j = 1; j < n; j++){
            if(nums[j] > mini){
                ans = max(ans, nums[j]-mini);
            }
            mini = min(mini, nums[j]);
        }
        return ans;
    }
};