class Solution {
public:
    void solve(vector<int> &nums, vector<int> &temp, set<vector<int>> &res, 
    unordered_set<int> &st){
        if(temp.size()==nums.size()){
            res.insert(temp);
            return;
        }

        for(int i =0; i < nums.size(); i++){
            if(st.find(i) == st.end()){
                temp.push_back(nums[i]);
                st.insert(i);

                solve(nums, temp, res, st);

                temp.pop_back();
                st.erase(i);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(), nums.end());

        set<vector<int>> res;
        vector<int> temp;
        unordered_set<int> st;
        solve(nums, temp, res, st);

        vector<vector<int>> ans;
        for(auto it: res){
            ans.push_back(it);
        }
        return ans;
    }
};