class Solution {
class DisjointSet{
public: 
    vector<int> parent,size;

    DisjointSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1);

        for(int i =0; i <=n; i++){
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
        } else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for(auto it: edges){
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u)== ds.findUPar(v)){
                return {u, v};
            } else{
                ds.unionBySize(u, v);
            }
        }
        return {};
    }
};