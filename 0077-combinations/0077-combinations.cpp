class Solution {
public: 
    void solve(vector<vector<int>> &res, vector<int>&temp, int st, int k, int n){
        if(k==0){
            res.push_back(temp);
            return;
        }

        if(st > n) return;

        temp.push_back(st);
        solve(res, temp, st+1, k-1, n);
        temp.pop_back();
        solve(res, temp, st+1, k, n);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        int start =1;
        solve(res, temp, start, k, n);
        return res;
    }
};