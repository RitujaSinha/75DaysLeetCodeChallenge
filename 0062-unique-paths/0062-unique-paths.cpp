class Solution {
public:

    int solve(int i, int j, int m, int n, vector<vector<int>> &t){
        if(i >= m || j >= n) return 0;

        if(i == m-1 && j == n-1) return 1;

        if(t[i][j] !=-1) return t[i][j];

        int right = solve(i+1, j, m, n, t);
        int down = solve(i, j+1, m, n, t);

        return t[i][j] = right+down;
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> t(m+1, vector<int> (n+1, -1));
        return solve(0, 0, m, n, t);
    }
};