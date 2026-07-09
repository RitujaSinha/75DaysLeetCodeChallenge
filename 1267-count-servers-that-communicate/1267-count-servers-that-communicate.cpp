class Solution {
class DisjointSet{
public:
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n+1, 0);
        size.resize(n+1);

        for(int  i=0; i <=n; i++){
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
            size[ulp_u] += size[ulp_v];
        } else{
            parent[ulp_v] = ulp_u;
            size[ulp_v] += size[ulp_u];
        }
    }
}; 
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        DisjointSet ds(m+n);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int col = j + m +1;
                    ds.unionBySize(i, col);
                }
            }
        }

        int ans =0;

        unordered_map<int, int> mpp;
        for(int i =0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int root = ds.findUPar(i);
                    mpp[root]++;
                }
            }
        }

        for(int i =0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    int root = ds.findUPar(i);
                    if(mpp[root] > 1) ans++;
                }
            }
        }
        return ans;
    }
};