class Solution {
public:
    using ll = long long;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

        vector<long long> dist(n, 1e18), ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        int mod = (int)(1e9+7);

        while(!pq.empty()){
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                int edW = it.second;

                if(edW + dis < dist[adjNode]){//first time arriving
                    dist[adjNode] = edW + dis;
                    pq.push({edW+dis, adjNode});
                    ways[adjNode] = ways[node];
                } else if(edW + dis == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};