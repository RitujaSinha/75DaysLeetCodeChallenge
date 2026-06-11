class Solution {
public:
    map<pair<int, int>, int> mp;
    int MOD = 1e9+7;

    // int solve(int n, int parity){
    //     if(n == 0){
    //         // if(sum % 2 == 1){
    //         //     return 1;
    //         // }
    //         // return 0;
    //         return parity==1;
    //     }

    //     if(mp.find({n, parity}) != mp.end()) return mp[{n, parity}];

    //     int one = solve(n-1, (parity+1) % 2);
    //     int two = solve(n-1, (parity+2) % 2);

    //     return mp[{n, parity}] = (one+two) % MOD;
    // }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int V = edges.size()+1;

        vector<vector<int>> adj(V+1);
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(V+1, 0);
        vis[0] = 1;

        queue<pair<int, int>> q;
        q.push({1, 0});// node, edgeW
        vis[1] = 1; 

        int maxEdges = 0;
        while(!q.empty()){
            int node = q.front().first;
            int edges = q.front().second;
            q.pop();

            maxEdges = max(maxEdges, edges);

            for(auto it: adj[node]){
                if(!vis[it]){
                    q.push({it, edges+1});
                    vis[it]=1;
                }
            }
        }
        if(maxEdges == 0) return 0;
        
        int result=1;
        for(int i =1; i <= maxEdges-1; i++){
            result= (result*2) % MOD;
        }

        return result;
    }
};