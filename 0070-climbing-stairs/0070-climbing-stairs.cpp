class Solution {
public:
    int climbStairs(int n) {

        if(n==1 || n== 2) return n;
        
        vector<int> dp(n+1, 0); // steps to reach n stairs
        dp[1] = 1; // 1 steps to reach 1 stair
        dp[2] = 2;

        // i+1, i+2

        // -1, 0 // out of bound

        for(int i = 3; i < n+1; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};



