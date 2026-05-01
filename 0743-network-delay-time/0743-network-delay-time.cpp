class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> v(n+1);
        for(auto &it: times){
            v[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[0] = 0;

        queue<pair<int, int>> q;
        q.push({k, 0});
        dist[k] = 0;

        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;

            q.pop();

            for(auto &it: v[node]){
                int nextNode = it.first;
                int w = it.second;

                if(d + w < dist[nextNode]){
                    dist[nextNode] = d+w;
                    q.push({nextNode, d+w});
                }
            }
        }
        return *max_element(dist.begin(), dist.end()) == INT_MAX ? -1 : *max_element(dist.begin(), dist.end());
    }
};