class Solution {
public:
    int f(int ind, int buy, int k, vector<int>& prices, int n,  vector<vector<vector<int>>> &t){
        if(ind == n || k == 0){
            return 0;
        }

        if(t[ind][buy][k] != -1) return t[ind][buy][k];

        int profit = 0;
        if(buy){
            profit += max(-prices[ind] + f(ind+1, 0, k, prices, n, t),
            0+ f(ind+1, 1, k, prices, n, t));
        } else{
            profit += max(prices[ind] + f(ind+1, 1, k-1, prices, n, t),
            0+ f(ind+1, 0, k, prices, n, t));
        }

        return t[ind][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> t(n, vector<vector<int>> (2, vector<int> (k+1, -1)));

        return f(0, 1, k, prices, n, t);
    }
};