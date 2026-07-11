class Solution {
class DisjointSet{
public:

    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1);

        for(int i = 0; i <= n; i++){
            parent[i] =i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);

        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0; i < edges.size(); i++){
            ds.unionBySize(edges[i][0], edges[i][1]);
        }

        vector<vector<int>> par(n);

        for(int i = 0; i < n; i++){
            par[ds.findUPar(i)].push_back(i);
        }
        

        int ans = 0;
        for(auto parent: par){
            if (parent.empty()) {
                continue;
            }
            int s = parent.size();
            bool complete = true;

            for(auto it: parent){
                if(adj[it].size() != s-1){
                    complete = false; //ek bhi sahi nhi hua to pura compoent hi complete nhi hoga
                    break;
                }
            }

            if(complete) ans++;
        }
        return ans;
    }
};