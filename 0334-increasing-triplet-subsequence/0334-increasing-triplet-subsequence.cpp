class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n, 1);

        unordered_map<int,int> mpp;
        for(int num: nums){
            mpp[num]++;
        }
        if(mpp.size() < 3) return false; // if only 2 value is there will be no triplet form

        if(nums[n-1] > nums[n-2] && nums[n-2] > nums[n-3]) return true; // manually handled this case

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    t[i] = max(t[i], t[j]+1);
                }

                if(t[i] == 3) return true;
            }
        }
        return false;
    }
};