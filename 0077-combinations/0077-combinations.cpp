class Solution {
public:
    void solve(int i,int k, vector<int> &num, vector<vector<int>> &res, vector<int> &temp){
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }

        if(i == num.size()) return;

        temp.push_back(num[i]);
        solve(i+1, k, num,res, temp);
        temp.pop_back();
        solve(i+1, k, num, res, temp);
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> num;
        for(int i = 1; i <=n; i++){
            num.push_back(i);
        }

        vector<vector<int>> res;
        vector<int> temp;
        solve(0,k, num, res, temp);
        return res;
    }
};