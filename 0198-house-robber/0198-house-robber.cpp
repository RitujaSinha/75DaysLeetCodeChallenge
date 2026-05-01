class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n+1, 0);
        t[1] = nums[0];

        for(int i = 2; i <= n; i++){
            
            int skip = t[i-1];
            int robb = t[i-2] + nums[i-1];

            t[i] = max(skip, robb);
        }
        return t[n];
    }
};