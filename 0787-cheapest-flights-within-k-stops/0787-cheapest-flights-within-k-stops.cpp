class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adj(n);
        for(auto &it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, INT_MAX);

        queue<pair<pair<int, int>, int>> q;
        q.push({{src, 0}, 0});

        while(!q.empty()){

            int node = q.front().first.first;
            int stops = q.front().first.second;

            int cost = q.front().second;
            q.pop();

            if(stops > k) continue;

            for(auto it: adj[node]){
                int nextNode = it.first;
                int price = it.second;


                if(price + cost < dist[nextNode]){
                    dist[nextNode] = price + cost;
                    q.push({{nextNode, stops+1}, dist[nextNode]});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};