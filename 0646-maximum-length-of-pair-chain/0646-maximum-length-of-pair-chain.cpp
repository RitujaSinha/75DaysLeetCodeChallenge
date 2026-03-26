class Solution {
public:
    int solve(vector<vector<int>>& pairs, int i, int P,  vector<vector<int>> &dp){
        if(i >= pairs.size()) return 0;


        if(P != -1 && dp[i][P] != -1) return dp[i][P];

        int take =0;
        if(P == -1 || pairs[i][0] > pairs[P][1]){
            take = 1 + solve(pairs, i+1, i, dp);
        }

        int skip = solve(pairs, i+1, P, dp);

        if(P != -1){
            dp[i][P] = max(take, skip);
        }

        return max(take, skip);

    }
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        return solve(pairs, 0, -1, dp);
    }
};