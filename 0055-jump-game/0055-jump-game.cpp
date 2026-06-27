class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;

        int far = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                far = max(far, i+nums[i]);
            }
            if(i != n-1 && far == i && nums[i] <=0) return false;
        }
        return true;
    }
};