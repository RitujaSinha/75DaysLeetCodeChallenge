class Solution {
public:
    bool can(vector<int>& nums, int maxOperations, int mid){
        long long ops = 0;

        for(int &x: nums){
            ops += (x-1)/mid;
        }
        return ops <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();

        int st = 1;
        int end = *max_element(nums.begin(), nums.end());

        int ans = end;

        while(st <= end){
            int mid = st + (end-st)/2;

            if(can(nums, maxOperations, mid)){
                ans = mid;
                end= mid-1;
            } else{
                st = mid+1;
            }
        }
        return ans;
    }
};