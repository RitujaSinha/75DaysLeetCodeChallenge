class Solution {
public:
    void solve(int i, vector<int>& nums,set<vector<int>> &res, vector<int>&temp){
        if(i == nums.size()){
            res.insert(temp);
            return;
        }

        // unordered_set<int> st;

        temp.push_back(nums[i]);
        solve(i+1, nums, res, temp);
        temp.pop_back();
        solve(i+1, nums, res, temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        set<vector<int>> res;
        vector<int> temp;
        solve(0, nums, res, temp);

        vector<vector<int>> ans;
        for(auto it: res){
            ans.push_back(it);
        }
        return ans;
    }
};