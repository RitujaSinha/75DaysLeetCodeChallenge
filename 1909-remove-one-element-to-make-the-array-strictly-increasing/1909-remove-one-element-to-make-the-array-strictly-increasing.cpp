class Solution {
public:
    bool isSorted(vector<int>& nums, int idx){

        int n = nums.size();
        int prev=-1;
        for(int i = 0; i < n; i++){
            if(i == idx) continue;

            if(prev!=-1 && nums[i] <= nums[prev]) return false;
            prev= i;
        }
        return true;
    }
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();

        for(int i =0; i < n; i++){
            if(isSorted(nums, i)){
                return true;
            }
        }
        return false;
    }
};