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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n *n);

        for(int row =0; row < n; row++){
            for(int col = 0; col< n; col++){
                if(grid[row][col] == 0) continue;

                int delrow[] = {-1, 0, 1, 0};
                int delcol[] = {0, -1, 0, 1};

                for(int i = 0; i < 4; i++){
                    int nrow = row+ delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                        int nodeNo = row*n+col;
                        int adjNodeNo = nrow*n+ncol;

                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        int mx =0;
         for(int row =0; row < n; row++){
            for(int col = 0; col< n; col++){
                if(grid[row][col] == 1) continue;

                int delrow[] = {-1, 0, 1, 0};
                int delcol[] = {0, -1, 0, 1};

                set<int> components;

                for(int i = 0; i < 4; i++){
                    int nrow = row+ delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                        components.insert(ds.findUPar(nrow*n+ncol));
                    }
                }
                int sizeTotal = 0;
            for(auto it: components){
                sizeTotal += ds.size[it];
            }
            mx =max(mx, sizeTotal+1);
            }
        }

        for(int cellNo = 0; cellNo < n*n; cellNo++){
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        return mx;
    }
};