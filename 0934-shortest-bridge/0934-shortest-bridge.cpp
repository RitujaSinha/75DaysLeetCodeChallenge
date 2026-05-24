class Solution {
public:
    void dfs(int row,int col, vector<vector<int>>& grid, vector<vector<int>>& vis,
    queue<pair<int,pair<int,int>>> &q){
         int n = grid.size();

        vis[row][col] = 1;
        q.push({0,{row,col}});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i =0; i< 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1
            && !vis[nrow][ncol]){
                dfs(nrow, ncol, grid, vis, q);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> vis(n, vector<int> (n, 0));

        queue<pair<int,pair<int,int>>> q;

        bool found = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j< n; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    // q.push({0, {i, j}}); //{flips, {row, col}}
                    dfs(i,j, grid, vis, q);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }

    
        

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int flip = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            // if(grid[r][c]==1) return flip;

            for(int i = 0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow>=0 && nrow < n && ncol>=0 && ncol < n){
                    if(grid[nrow][ncol]==1 && !vis[nrow][ncol]) return flip;

                    if(grid[nrow][ncol] == 0 && !vis[nrow][ncol]){
                    q.push({flip+1, {nrow, ncol}});
                    vis[nrow][ncol]= 1;
                    }
                }
            }
        }
        return -1;
    }
};