class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> v(n+1);
        for(auto &it: times){
            v[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[0] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
        q.push({0, k});
        dist[k] = 0;

        while(!q.empty()){
            int d = q.top().first;
            int node = q.top().second;

            q.pop();

            if(d > dist[node]) continue; //No need to calculate if greater

            for(auto &it: v[node]){
                int nextNode = it.first;
                int w = it.second;

                if(d + w < dist[nextNode]){
                    dist[nextNode] = d+w;
                    q.push({d+w, nextNode});
                }
            }
        }
        return *max_element(dist.begin(), dist.end()) == INT_MAX ? -1 : *max_element(dist.begin(), dist.end());
    }
};