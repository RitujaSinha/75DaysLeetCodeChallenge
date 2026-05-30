class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>> &res, vector<int>& temp, unordered_set<int> &st){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }


        for(int j =0; j < nums.size(); j++){
            if(st.find(nums[j]) == st.end()){
                temp.push_back(nums[j]);
                st.insert(nums[j]);

                solve(nums, res, temp, st);
                temp.pop_back();
                st.erase(nums[j]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        unordered_set<int> st;
        solve(nums, res, temp, st);
        return res;
    }
};