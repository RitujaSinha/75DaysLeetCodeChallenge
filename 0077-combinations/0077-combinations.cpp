class Solution {
public:
    void solve(int start,int k,int n, vector<vector<int>> &res, vector<int> &temp){
        if(k==0){
            res.push_back(temp);
            return;
        }

        if(start > n) return;

        temp.push_back(start);
        solve(start+1, k-1,n,res, temp);
        temp.pop_back();
        solve(start+1, k,n, res, temp);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(1,k,n, res, temp);
        return res;
    }
};