class Solution {
public:
    int t[46];
    int solve(int n){
        if(n==0) return 1;

        if(n < 0) return 0;

        if(t[n] != -1) return t[n];

        int oneSteps = solve(n-1);
        int twoSteps = solve(n-2);

        return t[n] = oneSteps + twoSteps;
    }
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
       return solve(n);
    }
};