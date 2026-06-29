class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int len = 0, zeros= 0;
        int l = 0, r=0;
        while(r< n){
            
            while(zeros > k){
                if(nums[l] == 0){
                    zeros--;
                }
                l++;
            }

            if(nums[r] == 0) zeros++;

            if(zeros <= k){
                len = max(len, r-l+1);
            }

            r++;
        }
        return len;
    }
};