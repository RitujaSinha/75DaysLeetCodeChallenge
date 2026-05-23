class Solution {
public:
    bool rotate(vector<int>& nums, vector<int> temp, int k){
        int n = nums.size();
        k=k %n;

        reverse(temp.begin(), temp.begin()+k);
        reverse(temp.begin()+k, temp.end());
        reverse(temp.begin(), temp.end());
        return temp==nums;
    }
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        for(int i = 0; i < n; i++){
            if(rotate(nums,temp, i)) return true;
        }
        return false;
    }
};