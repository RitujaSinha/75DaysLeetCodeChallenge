class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n =nums.size();

        sort(nums.begin(), nums.end());

        int l=0, r=0;
        int count =0;
        while(r< n){
            if((nums[r] - nums[l]) > k){
                count++;
                l=r;
            }

            r++;
        }
        count++;
        return count;
    }
};