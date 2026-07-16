class Solution {
class DisjointSet{
public:
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1);

        for(int i=0; i <= n; i++){
            parent[i] = i;
            size[i] =1;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        // int n = connections.size();

        DisjointSet ds(n);

        int cntExtra = 0;
        for(int i = 0; i < connections.size(); i++){

            int u= connections[i][0];
            int v = connections[i][1];

            if(ds.findUPar(u) == ds.findUPar(v)) cntExtra++;
            else{
                ds.unionBySize(u, v);
            }
        }

        int cntC = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i){
                cntC++;
            }
        }

        int ans  = cntC-1;
        return ans <= cntExtra ? ans : -1;
    }
};