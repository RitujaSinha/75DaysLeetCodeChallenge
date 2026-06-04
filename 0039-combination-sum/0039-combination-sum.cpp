class Solution {
public:
    void solve(int sum,int i, vector<vector<int>> &res, vector<int> &temp, vector<int>& candidates, int target){
        if(sum == target){
            res.push_back(temp);
            return;
        }

        if(sum > target) return;
        if(i == candidates.size()) return;
            
        temp.push_back(candidates[i]);
        solve(sum + candidates[i],i,  res, temp, candidates, target);
        temp.pop_back();
        solve(sum,i+1,  res, temp, candidates, target);

    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> temp;
        solve(0,0, res, temp, candidates, target);
        return res;
    }
};