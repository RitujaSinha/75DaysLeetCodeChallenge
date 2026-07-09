class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sm = accumulate(nums.begin(), nums.end(), 0);

        int val = (n * (n+1))/2;
        return val-sm;

    }
};