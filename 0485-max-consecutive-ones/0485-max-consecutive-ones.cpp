class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int maxi = 0, maximum = 0;
        for(int i =0; i < n; i++){
            if(nums[i] == 1){
                maxi++;
            } else{
                maxi = 0;
            }

            maximum = max(maximum, maxi);
        }
        return maximum;
    }
};