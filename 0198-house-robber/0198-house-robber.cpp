class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prevPrev = 0; //no house -> no money
        int prev = nums[0]; //just rob the first

        for(int i = 2; i <= n; i++){

            int robb = nums[i-1] + prevPrev;
            int skip = prev;

            int curr = max(robb, skip);

            prevPrev = prev;
            prev = curr;
        }
        return prev;
    }
};