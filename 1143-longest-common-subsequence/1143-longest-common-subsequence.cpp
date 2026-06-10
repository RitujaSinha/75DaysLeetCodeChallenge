class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &t){
        if(i == s1.size() || j == s2.size()){
            return 0;
        }

        if(t[i][j] != -1) return t[i][j];

        if(s1[i] == s2[j]){
            return t[i][j] = 1 + solve(i+1, j+1, s1, s2,t);
        } 
        return t[i][j] = max(solve(i+1, j, s1, s2, t), solve(i, j+1, s1, s2, t));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();

        vector<vector<int>> t(m, vector<int> (n, -1));
        return solve(0, 0, s1, s2, t);
    }
};