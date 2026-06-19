class Solution {
public:
    int solve(int ind, int buy, vector<int> &prices, vector<vector<int>> &t){

        if(ind == prices.size()){
            return 0; // no more profit i can make
        }   

        if(t[ind][buy] != -1) return t[ind][buy];

        int profit = 0;
        if(buy){
            int take = -prices[ind] + solve(ind+1, !buy, prices, t);
            int notTake = solve(ind +1, buy, prices, t);

            int best = max(take, notTake);

            profit += best;
        } else{
            int take = prices[ind] + solve(ind+1, !buy, prices, t);
            int notTake = solve(ind +1, buy, prices, t);

            int best = max(take, notTake);

            profit += best;
        }

        return t[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> t(n, vector<int> (2, -1));
        
        return solve(0, 1, prices, t);
    }
};