class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> m;
        for(int num: nums){
            m[num]++;
        }

        unordered_map<int, int> mpp;
        int ans = 0;
        int l =0, r=0;
        while(r< n){
            mpp[nums[r]]++;

            while(mpp.size() == m.size()){
                ans += n-r;

                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }

            r++;
        }
        return ans;
    }
};