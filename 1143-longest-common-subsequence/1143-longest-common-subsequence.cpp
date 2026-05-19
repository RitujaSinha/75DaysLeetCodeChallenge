class Solution {
public:
    int solve(string &s1, string &s2, int i, int j, 
        vector<vector<int>> &t){
        if(i >= s1.size() || j >= s2.size()){
            return 0;
        }

        if(t[i][j] != -1) return t[i][j];

        if(s1[i] == s2[j]){
            return t[i][j] = 1 + solve(s1, s2, i+1, j+1,t);
        } 
        return t[i][j] = max(solve(s1, s2, i+1, j, t), solve(s1, s2, i, j+1,t));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1= s1.size();
        int n2 = s2.size();

        vector<vector<int>> t(n1,vector<int> (n2, -1));
        return solve(s1, s2, 0, 0, t);
    }
};