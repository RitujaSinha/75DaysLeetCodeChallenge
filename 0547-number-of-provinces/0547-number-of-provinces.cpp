class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>>& isConnected){
        int n = isConnected.size();
        vis[node] = 1;

        for(int j = 0; j < n; j++){
            if(!vis[j] && isConnected[node][j]==1){
                dfs(j, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<int> vis(n, 0);

        int count = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                dfs(i, vis, isConnected);
            }
        }
        return count;
    }
};