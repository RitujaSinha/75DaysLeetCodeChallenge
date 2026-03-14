class Solution {
public:
    // bool leftInc(vector<int>& nums, int idx){
    //     if(idx == 0) return true;

    //     for(int i =1; i <= idx; i++){
    //         if(nums[i] <= nums[i-1]) return false;
    //     }
    //     return true;
    // }

    // bool rightDec (vector<int>& nums, int idx){
    //     if(nums.size() == 2 && idx+1==nums.size()-1) return true;
    //     // if(idx == nums.size()-1) return true;

    //     for(int i =idx+1; i < nums.size()-1; i++){
    //         if(nums[i] <= nums[i+1]) return false;
    //     }
    //     return true;
    // }

    long long splitArray(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefixSum(n);
        vector<long long> suffixSum(n);

        vector<bool> leftInc(n,true);
        vector<bool> rightDec(n,true);

         for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1] && leftInc[i-1])
            leftInc[i] = true;
            else
            leftInc[i] = false;
        }

       for(int i = n-2; i >= 0; i--){
        if(nums[i] > nums[i+1] && rightDec[i+1])
        rightDec[i] = true;
        else
        rightDec[i] = false;
        }

        prefixSum[0] = nums[0];
        for(int i=1; i < n; i++){
            prefixSum[i] = prefixSum[i-1]+ nums[i];
        }

        suffixSum[n-1] = 0;
        for(int i = n-1; i>=1; i--){
            suffixSum[i-1] = suffixSum[i] + nums[i];
        }

        long long mini = LLONG_MAX;
        for(int i =0; i < n-1; i++){
            if(leftInc[i] && rightDec[i+1]){
            mini = min(mini, llabs(prefixSum[i] - suffixSum[i]));
            }
        }
        return mini == LLONG_MAX ? -1 : mini;
    }
};