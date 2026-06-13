class Solution {
public:
    int solve(int i, int P, vector<vector<int>>& pairs, vector<vector<int>> &t){
        if(i == pairs.size()){
            return 0;
        }

        if(t[i][P+1] != -1) return t[i][P+1];

        int take = 0;
        if(P == -1 || pairs[i][0] > pairs[P][1]){
            take = 1 + solve(i+1, i, pairs, t);
        }
        int notTake = solve(i+1, P, pairs, t);

        return  t[i][P+1] = max(notTake, take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());

        vector<vector<int>> t(n, vector<int>(n+1, -1));

        return solve(0,-1, pairs, t);
    }
};