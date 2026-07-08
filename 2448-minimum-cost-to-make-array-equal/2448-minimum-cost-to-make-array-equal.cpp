class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();

        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++){
            vec.push_back({nums[i], cost[i]});
        } 

        sort(vec.begin(), vec.end());

        long long totalCost = 0;
        for(int c: cost){
            totalCost +=c;
        }

        long long median = 0;
        median = (totalCost + 1)/2;

        long long prefCost = 0;
        long long target = 0;
        for(int i=0; i <n; i++){
            prefCost += vec[i].second;

            if(prefCost >= median){
                target = vec[i].first;
                break;
            }
        }

        long long total = 0;
        for(int i =0; i < n; i++){
            long long c = vec[i].second;
            long long el = vec[i].first;

            total += (abs(target-el) * c);
        }
        return total;
    }
};