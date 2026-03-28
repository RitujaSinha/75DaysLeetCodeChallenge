class Solution {
public:
    int n;
    int m;
    int t[501][501];
    int solve(string &s1, string &s2, int i, int j){
        if(i >= n || j >= m) return 0;

        if(t[i][j] != -1){
            return t[i][j];
        }

        if(s1[i] == s2[j]){
            return t[i][j]= 1 + solve(s1, s2, i+1, j+1);
        }

        int a =solve(s1, s2, i+1, j);
        int b =solve(s1, s2, i, j+1);

        return t[i][j]= max(a, b);
    }
    int minDistance(string s1, string s2) {
        n = s1.size();
        m = s2.size();
        memset(t, -1, sizeof(t));
        int res = solve(s1, s2, 0, 0);

        return (n-res) + (m -res);
    }
};