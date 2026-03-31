// class Solution {
// public:
        //  Left to right travel
//     // int solve(string &s1, string &s2, int i, int j){
//     //     if(i >= s1.size() || j >= s2.length()) return 0;

//     //     if(s1[i] == s2[j]){
//     //         return 1 + solve(s1, s2, i+1, j+1);
//     //     }

//     //     return max(solve(s1, s2, i+1, j), solve(s1, s2, i, j+1));
//     // }
//     int longestCommonSubsequence(string s1, string s2) {
//         //   return solve(s1, s2, 0, 0);
//     }
// };

//Right to left traversal
class Solution {
public:
    int t[1001][1001];
    int solve(string &s1, string &s2, int m, int n){
        if(m==0 || n==0) return 0;

        if(t[m][n] != -1) return t[m][n];

        if(s1[m-1] == s2[n-1]){
            return t[m][n]= 1 + solve(s1, s2, m-1, n-1);
        }

        return t[m][n] = max(solve(s1, s2, m-1, n), solve(s1, s2, m, n-1));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        memset(t, -1, sizeof(t));
        
        return solve(s1, s2, m, n);
    }
};