class Solution {
public:
    int solve(int n, vector<int> &t){
         if(n == 0) return 1;

        if(n < 0) return 0;

        if(t[n] != -1) return t[n];

        int oneStep = solve(n-1, t);
        int twoSteps = solve(n-2, t);

        return t[n] = oneStep + twoSteps;
    }
    int climbStairs(int n) {
        vector<int> t(n+1, -1);

        return solve(n, t);
    }
};