class Solution {
public:
    int t[501][501];
    int solve(string &s1, string &s2, int i, int j){
        if(i == s1.size()){
            return s2.size()-j;
        } else if(j == s2.size()){
            return s1.size()-i;
        }

        if(t[i][j] != -1) return t[i][j];

        if(s1[i] == s2[j]){
            return t[i][j] = solve(s1, s2, i+1, j+1);
        }

        int insert = 1 + solve(s1, s2, i, j+1);
        int del = 1 + solve(s1, s2, i+1, j);
        int replace = 1 + solve(s1, s2, i+1, j+1);

        return t[i][j] = min({insert, del, replace});
    }
    int minDistance(string s1, string s2) {
        memset(t, -1,sizeof(t));
        return solve(s1, s2, 0, 0);
    }
};