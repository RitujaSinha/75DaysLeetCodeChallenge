class Solution {
public:
    long long dfs(int node,int parent, vector<vector<int>> &adj, vector<int>& baseTime,  vector<int> &vis){
        if(adj[node].size() == 1 && parent != -1){
            return (long long)baseTime[node];
        }

        vis[node] = 1;

        long long earliest = LLONG_MAX;
        long long latest = LLONG_MIN;

        long long best = 0;
        for(auto it: adj[node]){
            if(parent == it) continue;

            if(!vis[it] && parent != it)
           best =  dfs(it,node, adj, baseTime, vis);

           earliest = min(earliest, best);
        latest = max(latest, best);
        }


        long long ownDuration  = (latest-earliest) + baseTime[node];
        return ownDuration + latest;

    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        if(n==1){
            return baseTime[0];
        }
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);

        return dfs(0,-1, adj, baseTime, vis);
    }
};