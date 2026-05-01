class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev = nums[0];
        int prevPrev = 0;

        for(int i = 2; i <= n; i++){
            
            int curr = max({prev, prevPrev + nums[i-1]});

            prevPrev=prev;
            prev =curr;

        }
        return prev;
    }
};