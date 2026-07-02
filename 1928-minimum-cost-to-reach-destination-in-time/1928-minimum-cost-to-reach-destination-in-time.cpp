class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        vector<vector<pair<int, int>>>adj(n);
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;//cost, time, node
        pq.push({passingFees[0],{0, 0}});

        vector<int> minCost(n, INT_MAX);
        vector<int> minTime(n, INT_MAX);
        minCost[0] = passingFees[0];
        minTime[0] = 0;

        while(!pq.empty()){
            int c = pq.top().first;
            int t = pq.top().second.first;
            int node = pq.top().second.second;

            pq.pop();

            if(t > maxTime) continue;

            if(node == n-1){
                return c;
            }

            for(auto it: adj[node]){
                int adjNode = it.first;
                int time = it.second;

                if(t + time <= maxTime){
                    if(c + passingFees[adjNode] < minCost[adjNode]
                    || t +time < minTime[adjNode]){
                        pq.push({c+passingFees[adjNode], {t + time, adjNode}});
                        minCost[adjNode] = c+passingFees[adjNode];
                        minTime[adjNode] = t + time;
                    }
                }
            }
        }
        return -1;
    }
};