class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();

        sort(costs.begin(), costs.end(), [](vector<int>&a, vector<int> &b){
            
            return (b[1]-b[0]) < (a[1]-a[0]);
        });

        int cost = 0;
        for(int i = 0; i < n/2; i++){
            cost += costs[i][0];
        }

        for(int i = n/2; i < n; i++){
            cost += costs[i][1];
        }

        return cost;
    }
};