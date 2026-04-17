class Solution {
public:
    bool bfs(int start, int n, vector<vector<int>> &adj, vector<int> &color){
        queue<pair<int, int>> q;
        q.push({start, 0});
        color[start] = 0;

        while(!q.empty()){
            int node = q.front().first;
            int c = q.front().second;
            q.pop();

            for(auto it: adj[node]){
                if(color[it] == color[node]){
                    return false;
                } else if(color[it] == -1){
                    color[it] = !c;
                    q.push({it, !c});
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<vector<int>> adj(n + 1);//Creating a adjcacency list
        for(auto it: dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // queue<pair<int, int>> q;

        vector<int> color(n+1, -1);

        for(int i =0; i < n; i++){
            if(color[i] == -1){
                if(bfs(i, n, adj, color) == false){
                    return false;
                }
            }
        }

        return true;
    }
};