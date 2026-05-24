class Solution {
public:
    void solve(int i, vector<int> &nums,vector<int>& temp, vector<vector<int>> &res){
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i+1, nums, temp, res);
        temp.pop_back();

        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]) idx++;
        solve(idx, nums, temp, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        solve(0,nums, temp, res);
        return res;
    }
};