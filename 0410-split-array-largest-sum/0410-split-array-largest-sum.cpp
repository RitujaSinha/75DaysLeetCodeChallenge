class Solution {
public:
    bool isValid(vector<int>& nums, int k, int minAllowed){

        int stud = 1, pages= 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > minAllowed) return false;

            if(pages+nums[i] <= minAllowed){
                pages += nums[i];
            } else{
                stud++;
                pages = nums[i];
            }
        }
        return stud <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int st = 1;
        int end = accumulate(nums.begin(), nums.end(), 0);
        
        int ans =0;
        while(st <= end){
            int mid = st + (end-st)/2;

            if(isValid(nums, k, mid)){
                ans = mid;
                end = mid-1;
            } else{
                st= mid+1;
            }
        }
        return ans;
    }
};