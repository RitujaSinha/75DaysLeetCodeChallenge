class Solution {
public:
    void solve(int i, int P, vector<int>& nums, set<vector<int>> &result, vector<int> &temp){
        if(temp.size() >= 2){
            result.insert(temp);
            // return;
        }

        if(i == nums.size()) return;

        if(P <= nums[i]){
            temp.push_back(nums[i]);
            solve(i+1, nums[i], nums, result, temp);
            temp.pop_back();
        } 

        solve(i+1, P, nums, result, temp);

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>> result;
        vector<int> temp;
        solve(0,-200, nums, result, temp);

        vector<vector<int>> ans;
        for(auto it:result){
            ans.push_back(it);
        }
        return ans;

    }
};