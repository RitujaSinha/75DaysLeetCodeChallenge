class Solution {
public:
    int robRange(vector<int>& nums, int l, int r){

        int prevPrev = 0;
        int prev = 0;

        for(int i = l; i <= r; i++){
            int curr = max(prev, prevPrev + nums[i]);

            prevPrev = prev;
            prev= curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n ==2) return max(nums[0], nums[1]);

        return max(robRange(nums, 0, n-2), robRange(nums,1, n-1));
    }
};