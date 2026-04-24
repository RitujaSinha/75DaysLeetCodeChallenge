class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int currSum =0, maxSum = INT_MIN;
        for(int i =0; i < n; i++){
            currSum += nums[i];

            if(currSum < 0) currSum =0;
            maxSum = max(maxSum, currSum);
        }

        int minSum = INT_MAX;
        currSum =0;
        for(int i =0; i < n; i++){
            currSum += nums[i];

            if(currSum > 0) currSum =0;
            minSum = min(minSum, currSum);
        }
        return max(abs(minSum), maxSum);
    }
};