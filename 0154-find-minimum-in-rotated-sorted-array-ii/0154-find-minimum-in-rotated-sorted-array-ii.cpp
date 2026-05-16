class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int st = 0, end = n-1;
        
        int ans = INT_MAX;
        while(st <= end){
            int mid = st + (end-st)/2;

            if(nums[st] == nums[end]){
                ans = min(nums[st], ans);
                st++; end--;
                continue;
            }

             ans=min(ans, nums[mid]);

            if(nums[st] <= nums[mid]){
                ans = min(nums[st], ans);
                st = mid+1;
            } else{
                ans = min(nums[end], ans);
                end = mid-1;
            }
        }
        return ans;
    }
};