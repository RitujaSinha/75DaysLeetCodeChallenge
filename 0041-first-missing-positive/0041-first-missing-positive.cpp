class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        int maxi = *max_element(nums.begin(), nums.end());
        // sort(nums.begin(), nums.end());

        unordered_map<int, int> mpp;
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        for(int i = 1; i <= max(maxi, n); i++){
            if(mpp.find(i) == mpp.end()) return i;
        }
        return maxi+1;
    }
};