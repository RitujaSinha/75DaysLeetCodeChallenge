class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> t(n+1, vector<int> (2, 0));
        t[n][0] = t[n][1] = 0;

        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[ind] + t[ind+1][0], t[ind+1][1]);
                } else{
                    profit = max(prices[ind] + t[ind+1][1],t[ind+1][0]) ;
                }
                t[ind][buy] = profit;
            }
        }   
        return t[0][1];
    }
};