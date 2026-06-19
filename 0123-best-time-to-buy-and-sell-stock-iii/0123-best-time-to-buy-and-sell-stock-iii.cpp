class Solution {
public:
    int solve(int idx, int buy,int transactions, vector<int>& prices, int n, 
    vector<vector<vector<int>>> &t){
        if(idx == n){
            return 0;
        }

        if(transactions <= 0){
            return 0;
        }
        
        if(t[idx][buy][transactions] != -1) return t[idx][buy][transactions];

        int profit = 0;
        if(buy){
            profit += max(-prices[idx]+ solve(idx+1, 0, transactions-1, prices, n, t),
            solve(idx+1, 1, transactions, prices, n, t));
        } else{
            profit += max(prices[idx]+ solve(idx+1, 1, transactions-1, prices, n, t),
            solve(idx+1, 0, transactions, prices, n, t));
        }

        return t[idx][buy][transactions]=  profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> t(n, vector<vector<int>> (2, vector<int> (5, -1)));
        return solve(0, 1, 4, prices, n, t);
    }
};