class Solution {
public:
    void dfs(vector<vector<int>> &adj, int node, vector<int> &vis){
        vis[node] = 1;

        for(auto &it: adj[node]){
            if(!vis[it]){
                dfs(adj, it, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj(n+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                }
            }
        }


        vector<int> vis(n+1, 0);

        int count  = 0;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                count++;
                dfs(adj, i, vis);
            }
        }
        return count;
    }
};