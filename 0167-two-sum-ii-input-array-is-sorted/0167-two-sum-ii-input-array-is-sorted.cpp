class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        int i =0, j = n-1;
        while(i < j){
            int pair = nums[i]+ nums[j];

            if(pair == target){
                return {i+1, j+1};
            } else if(pair < target){
                i++;
            } else{
                j--;
            }
        }
        return {-1, -1};
    }
};