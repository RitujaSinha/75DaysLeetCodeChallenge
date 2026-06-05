class Solution {
public:
    void solve(int idx, vector<vector<int>> &res, vector<int> &temp, vector<int>& arr, int  target){
            if(target == 0){
                res.push_back(temp);
            }


        for(int i = idx; i < arr.size(); i++){
            if(i > idx && arr[i] == arr[i-1]) continue;

            if(arr[i] > target) break;
            temp.push_back(arr[i]);
            solve(i+1, res, temp, arr, target-arr[i]);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> temp;
        solve(0, res, temp, candidates, target);
        return res;
    }
};

// numbers can only be used once
// solution must contain the unique combinations
