class Solution {
public:
    int t[1000];
    int solve(vector<int>& cost, int i){
        if(i >= cost.size()){
            return 0;
        }

        if(t[i] != -1) return t[i];

        int oneStep =cost[i] + solve(cost, i+1);
        int twoStep =cost[i] + solve(cost, i+2);

        return t[i] = min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(t, -1, sizeof(t));

        int take_0th_index = solve(cost, 0);
        int take_1st_index = solve(cost, 1);

        return min(take_0th_index,take_1st_index);
    }
};