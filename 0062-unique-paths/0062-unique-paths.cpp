class Solution {
public:
    int t[101][101];
    int solve(int m, int n, int i, int j){
        if(i == m-1 && j == n-1) return 1;

        if(i> m || j > n){
            return 0;
        }

        if(t[i][j] != -1) return t[i][j];

        int down = solve(m, n, i+1, j);
        int right = solve(m , n, i, j+1);

        return t[i][j] = down+right;
    }
    int uniquePaths(int m, int n) {
        memset(t, -1, sizeof(t));
        return solve(m, n, 0, 0);
    }
};