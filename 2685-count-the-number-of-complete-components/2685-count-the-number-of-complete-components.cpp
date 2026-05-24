class Solution {
class DisjointSet{
public:
vector<int> parent, rank, size;

DisjointSet(int n){
    rank.resize(n+1, 0);
    parent.resize(n+1);
    size.resize(n+1);

    for(int i = 0; i <=n; i++){
        parent[i] = i;
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
        } else {
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

        for(int i = 0; i < n; i++){
            for(auto it: adj[i]){
                ds.unionBySize(i, it);
            }
        }

        unordered_map<int, int> nodeCount;//node count
        for(int i = 0; i < n; i++){
            int p = ds.findUPar(i);
            nodeCount[p]++;
        }

        unordered_map<int, int> edgeCount;//edge count
        for(auto it: edges){
            int p = ds.findUPar(it[0]);
            edgeCount[p]++;
        }

        int ans=0;
        for(auto it: nodeCount){
            int parent = it.first;
            int nodes = it.second;

            int edges = edgeCount[parent];

            if(edges == (nodes *(nodes-1)/2)) ans++;
        }
        return ans;
    }
};