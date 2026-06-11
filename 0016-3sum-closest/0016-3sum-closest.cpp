class Solution {
public:
    pair<int, int> twoSum(int st, vector<int>&nums, int firstVal, int target){
        int n = nums.size();
        int i = st, j = n-1;

        int sm =0;
        int ans =INT_MAX;
        while(i < j){
            int pair = nums[i] + nums[j];
            
            if(ans >  abs((firstVal + pair)-target)){
                ans =  abs((firstVal + pair)-target);
                sm = firstVal + pair;
            }
           
            
            if(firstVal + pair < target) i++;
            else if( firstVal + pair > target) j--;
            else{
                 i++; j--;
            }

        }
        return {ans,sm};
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int ans =INT_MAX;
        int sm= 0;
        for(int i =0; i < n-2; i++){
            pair<int, int> val = twoSum(i+1, nums, nums[i], target);

            if(ans > val.first){
                ans = val.first;
                sm = val.second;
            }
        }
        return sm;
    }
};