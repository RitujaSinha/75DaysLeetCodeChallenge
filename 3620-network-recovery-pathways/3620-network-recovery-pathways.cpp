class Solution {
public:
    using ll = long long;
    bool isValid(int maxPath, vector<vector<pair<int, int>>> adj, vector<bool> online, long long k){
        int n = online.size();

        priority_queue<pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>> pq;

        vector<ll> dist(n, LLONG_MAX);

        pq.push({0,0});
        dist[0] = 0;
        
        while(!pq.empty()){
            long long cost = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(cost > k) continue;
            if(cost > dist[node]) continue;

            if(node == n-1){
                return true;
            }

            for(auto it: adj[node]){
                int adjNode = it.first;
                int c = it.second;

                if(online[adjNode]){
                    long long newCost = c + cost;

                    if(newCost < dist[adjNode] && c >= maxPath){
                        dist[adjNode] = newCost;
                        pq.push({newCost, adjNode});

                    }
                }
                
            }
        }   
        return false;

    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);
        int maxi = INT_MIN;
        for(auto it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            maxi = max(maxi, it[2]);
        }

        int st = 0;
        int end = maxi;

        int ans = -1;
        while(st<= end){
            int mid = st + (end-st)/2;

            if(isValid(mid, adj, online, k)){
                ans = mid;
                st = mid+1;
            } else{
                end=mid-1;
            }
        }  
        return ans;
    }
};