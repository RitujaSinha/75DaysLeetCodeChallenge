class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < m; i++){
            for(int j =0; j < n; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;

        for(int d =0; d <= m+n-2; d++){
            
            if(d % 2==0)
            reverse(mp[d].begin(), mp[d].end());

            for(int &x: mp[d]){
                ans.push_back(x);
            }
        }
        return ans;
    }
};