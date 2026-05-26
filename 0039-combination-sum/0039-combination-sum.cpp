class Solution {
public:
    void solve(int i,int sum, vector<int>& candidates, int target,set<vector<int>> &res,
      vector<int> temp){
        if(sum == target){
            // sort(temp.begin(), temp.end());
            res.insert(temp);
            return;
        }

        if(i == candidates.size()) return;

        if(sum > target) return;

        temp.push_back(candidates[i]);
        solve(i,sum + candidates[i], candidates, target, res, temp);
        temp.pop_back();
        solve(i+1, sum, candidates, target, res, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> temp;
        solve(0,0, candidates, target, res, temp);

        vector<vector<int>> ans;
        for(auto it: res){
            ans.push_back(it);
        }
        return ans;
    }
};