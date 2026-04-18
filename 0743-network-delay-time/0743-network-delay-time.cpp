class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[0] = -1;

        queue<pair<int, int>> q;
        q.push({k, 0});
        dist[k] = 0;

        while(!q.empty()){
            int node = q.front().first;
            int time = q.front().second;

            q.pop();

            for(auto &it: adj[node]){
                int nextNode = it.first;
                int t = it.second;

                if(t + time < dist[nextNode]){
                    dist[nextNode] = t+time;
                    q.push({nextNode, dist[nextNode]});
                }
            }
        }
        return *max_element(dist.begin(), dist.end()) == INT_MAX ? -1 : 
        *max_element(dist.begin(), dist.end());
    }
};