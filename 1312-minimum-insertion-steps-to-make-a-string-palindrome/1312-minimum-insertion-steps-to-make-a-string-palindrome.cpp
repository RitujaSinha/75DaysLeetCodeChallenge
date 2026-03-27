class Solution {
public:
    int t[501][501];
    int solve(string &s1, string &s2, int i, int j){
        if(i >= s1.size() || j >= s2.size()) return 0;

        if(t[i][j] != -1) return t[i][j];

        if(s1[i] == s2[j]){
            return t[i][j]=  1 + solve(s1, s2, i+1, j+1);
        }

        return t[i][j] = max(solve(s1, s2, i+1, j), solve(s1, s2, i, j+1));
    }
    int minInsertions(string s) {
        int n = s.size();

        string s1 = s;
        string s2 = s1;
        memset(t, -1, sizeof(t));

        reverse(s2.begin(), s2.end());

        return n- solve(s1, s2, 0, 0);
    }
};