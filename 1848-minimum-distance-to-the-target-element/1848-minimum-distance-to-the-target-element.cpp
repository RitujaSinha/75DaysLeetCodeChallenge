class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();

        int val = INT_MAX;
        for(int i=0; i <n; i++){
            if(nums[i] == target){
                // idx =i;
                val = min(abs(i-start), val);
            }
        }
        return val;
    }
};