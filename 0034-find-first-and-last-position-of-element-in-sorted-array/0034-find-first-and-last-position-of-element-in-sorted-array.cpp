class Solution {
public:
    int firstOcc(vector<int>& nums, int target){
        int n = nums.size();

        int st = 0, end = n-1;
        int ans  =-1;
        while(st <= end){
            int mid = st + (end-st)/2;

            if(nums[mid] == target){
                ans = mid;
                end = mid-1; 
            } else if(nums[mid] > target){
                end = mid-1;
            } else{
                st = mid+1;
            }
        }
        return ans;
    }

     int lastOcc(vector<int>& nums, int target){
        int n = nums.size();

        int st = 0, end = n-1;
        int ans  =-1;
        while(st <= end){
            int mid = st + (end-st)/2;

            if(nums[mid] == target){
                ans = mid;
                st = mid+1; 
            } else if(nums[mid] > target){
                end = mid-1;
            } else{
                st = mid+1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        return {firstOcc(nums, target), lastOcc(nums, target)};
    }
};