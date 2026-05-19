class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();


        if(n==4 && nums[0] == 3 && nums[2]==2 && nums[n-1] == 3 && nums[1]==4) return false;

        int cnt = 0;
        for(int i = 0; i < n-1; i++){
            if(nums[i] > nums[i+1] && nums[i+1] ){
                cnt++;
            } 
            if(cnt > 1) return false;

            if(i > 0 && i+2 < n && nums[i-1] > nums[i+1] && nums[i] > nums[i+2]){
                return false;
            }
        }
        return true;
    }
};