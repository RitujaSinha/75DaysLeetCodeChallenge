class Solution {
public:
    int solve(vector<int> &arr, int k,vector<int> &dp){
    if(k == 0){
        return 0;
    }
    if(k < 0) return INT_MAX;

    if(dp[k] != -1) return dp[k];

    int a =INT_MAX;
    for(int i =0; i < arr.size(); i++){
        int t = solve(arr, k-arr[i], dp);
        if(t != INT_MAX)
        a = min(a, 1 +t);
    }
    
    return dp[k] = a;
}
    int coinChange(vector<int>& arr, int amount) {
    vector<int> dp(amount+1, -1);

    int res = solve(arr, amount, dp);

    return res == INT_MAX ? -1 : res;
    }
};