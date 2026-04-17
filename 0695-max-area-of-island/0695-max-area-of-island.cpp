class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        int area  =0;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();

            area++;

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1}; 

            for(int i =0; i < 4; i++){
                
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >=0 && nrow < m && ncol < n && ncol >=0 && grid[nrow][ncol] == 1
                && !vis[nrow][ncol]){
                    q.push({nrow, ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));

        int maxArea= 0;
        for(int i =0; i < m; i++){
            for(int j =0; j < n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    maxArea = max(bfs(i, j, grid, vis), maxArea);
                }
            }
        }
        return maxArea;
    }
};