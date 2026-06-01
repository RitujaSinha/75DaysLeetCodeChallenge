class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        if(n <= 2){
            return accumulate(cost.begin(), cost.end(), 0);
        }

        sort(cost.begin(), cost.end());

        int ans = 0, count = 0;
        for(int i =  n-1; i >=0; i--){
            count++;
            if(count <= 2) ans+= cost[i];
            else count = 0;
        }
        return ans;
    }
};