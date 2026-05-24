class Solution {
public:
    void solve(int i, vector<int>& nums,vector<int>& temp, vector<vector<int>> &res,
     unordered_set<int> &st){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(st.find(nums[i]) == st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                solve(i, nums, temp, res, st);

                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        unordered_set<int> st;

        solve(0, nums, temp, res, st);
        return res;
    }
};