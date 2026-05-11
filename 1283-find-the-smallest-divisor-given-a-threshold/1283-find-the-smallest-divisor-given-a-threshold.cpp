class Solution {
public:
    bool isValid(vector<int>& nums,int threshold, int divisor){
        int n = nums.size();

        int sum  =0;
        for(int i = 0; i < n; i++){
            sum += ceil((double)nums[i]/divisor);
        }
        if(sum <= threshold) return true;

        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int st = 1, end = *max_element(nums.begin(), nums.end());

        int ans = 0;
        while(st <= end){
            int mid = st+ (end-st)/2;

            if(isValid(nums,threshold, mid)){
                ans=mid;
                end = mid-1;
            } else{
                st =mid+1;
            }
        }
        return ans;
    }
};