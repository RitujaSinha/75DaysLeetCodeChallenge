class Solution {
public:
    long long bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        long long sum = 0;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            sum += grid[r][c];

            for(int i = 0; i < 4; i++){
                
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow < m && ncol >=0 && ncol < n && !vis[nrow][ncol] 
                && grid[nrow][ncol] != 0){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));


        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0 && !vis[i][j]){
                    long long sum = bfs(i, j, grid, vis);
                    if(sum % k == 0) count++;
                }
            }
        }
        return count;
    }
};