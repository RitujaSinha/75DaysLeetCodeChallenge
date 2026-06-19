class Solution {
public:
     int f(int ind, int buy, int n, vector<int>& prices, int fee, vector<vector<int>> &t){
        if(ind >= n) return 0; //ind+2 may become greater than n

        if(t[ind][buy] != -1) return t[ind][buy];

        int profit = 0;
        if(buy){
            int buyy = -prices[ind] + f(ind+1, 0, n, prices,fee, t);
            int notBuyy = 0 + f(ind+1, 1, n, prices,fee, t);

            profit += max(buyy, notBuyy);
        } else{
            int sell = prices[ind] - fee + f(ind+1, 1, n, prices,fee, t);
            int notSell = f(ind+1, 0, n, prices,fee, t);

            profit += max(sell, notSell);
        }
        return  t[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> t(n, vector<int> (2, -1));

        return f(0, 1, n, prices,fee, t);
    }
};