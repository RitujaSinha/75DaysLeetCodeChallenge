class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> equal, left, right;

        for(int i = 0; i < n; i++){
            if(nums[i] < pivot){
                left.push_back(nums[i]);
            } else if(nums[i] == pivot){
                equal.push_back(nums[i]);
            } else{
                right.push_back(nums[i]);
            }
        }

        vector<int> ans;

        for(int i =0; i < left.size(); i++){
            ans.push_back(left[i]);
        }
        for(int i =0; i < equal.size(); i++){
            ans.push_back(equal[i]);
        }
        for(int i =0; i < right.size(); i++){
            ans.push_back(right[i]);
        }
        return ans;
    }
};