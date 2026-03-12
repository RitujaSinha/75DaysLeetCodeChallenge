class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        for(int i =0; i < n; i++){
            int val = nums[i];
            int more = target-val;

            if(!mpp.empty() && mpp.find(more) != mpp.end()){
                int idx = mpp[more];
                return {i, idx};
            }
            mpp[nums[i]] = i; 
        }
        return {-1, -1};
    }
};