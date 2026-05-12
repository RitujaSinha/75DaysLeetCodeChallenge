class Solution {
public:
    bool isValid(vector<int>& nums, int k, int maxAllowed){
        int n = nums.size();

        int pages = 0;
        int stud = 1;

        for(int i = 0;i < n; i++){
            if(nums[i] > maxAllowed) return false;

            if(pages + nums[i] <= maxAllowed){
                pages+=nums[i];
            } else{
                stud++;
                pages= nums[i];
            }
        }
        return stud <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int st = *min_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);

        int ans = 0;
        while(st <= end){
            int mid = st + (end-st)/2;

            if(isValid(nums, k, mid)){
                ans= mid;
                end = mid-1;
            } else{
                st = mid+1;
            }
        }
        return ans;
    }
};