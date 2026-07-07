class Solution {
public:
    int dfs(vector<vector<int>> &adj, int node, int parent, vector<bool>& hasApple){

        int time = 0;
        for(int &child: adj[node]){
            if(child == parent) continue;

            int time_from_child = dfs(adj, child, node, hasApple);

            if(time_from_child > 0 || hasApple[child]){
                time += 2 + time_from_child;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(adj, 0, -1, hasApple);
    }
};