class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n =nums.size();

        int currSum =0, maxSum =INT_MIN;

        int startIdx = -1, endIdx =-1;
        int start =-1;
        for(int i =0; i< n; i++){
            if(currSum ==0) start = i;

            currSum += nums[i];

            if(maxSum < currSum){
                maxSum = currSum;
                startIdx = start;
                endIdx = i;
            }

            if(currSum < 0) currSum =0;
        }



         // Print subarray
         //folow up
        cout << "Subarray: ";
        for(int i = startIdx; i <= endIdx; i++){
            cout << nums[i] << " ";
        }
        cout << endl;

        return maxSum;
    }
};