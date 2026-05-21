class Solution {
public:
    bool isValid(int target, vector<int>& nums, int minLen){
        int n = nums.size();

        int l = 0, r=0;
        int sum = 0;
        while(r < n){
            sum += nums[r];

            if(r-l+1 > minLen){
                sum-=nums[l];
                l++;
            }

            if(sum >= target) return true;
            r++;
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        
        int st = 1, end = n;
        int ans=0;
        while(st <= end){
            int mid = st + (end-st)/2;

            if(isValid(target, nums, mid)){
                ans = mid;
                end = mid-1;
            } else{
                st=mid+1;
            }
        }
        return ans;
    }
};