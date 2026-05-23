class Solution {
public:
    void solve(int i, vector<int>& nums,vector<vector<int>> &res, vector<int>& temp){
        if(i==nums.size()){
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i+1, nums, res, temp);
        temp.pop_back();
        solve(i+1, nums, res, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(0, nums, res, temp);
        return res;
    }
};