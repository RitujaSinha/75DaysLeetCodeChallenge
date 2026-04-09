class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        queue<pair<int, int>> nodes;

        nodes.push({row, col});

        while(!nodes.empty()){
            auto it = nodes.front();
            nodes.pop();

            int r = it.first;
            int c = it.second;

            //left
            if(c-1>=0 && grid[r][c-1] == '1' && !vis[r][c-1]){
                vis[r][c-1] = 1;
                nodes.push({r, c-1});
            }

            //down
            if(r+1 < n && grid[r+1][c] =='1' && !vis[r+1][c]){
                vis[r+1][c] = 1;
                nodes.push({r+1, c});
            } 

            //right
            if(c+1 < m && grid[r][c+1] == '1' && !vis[r][c+1]){
                vis[r][c+1] = 1;
                nodes.push({r, c+1});
            } 

            //up
            if(r-1 >= 0 && grid[r-1][c] =='1' && !vis[r-1][c]){
                vis[r-1][c] = 1;
                nodes.push({r-1, c});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        int count =0;
        for(int row = 0; row< n; row++){
            for(int col =0; col < m; col++){
                if(grid[row][col] == '1' && vis[row][col] == 0){
                    count++;
                    bfs(row, col, grid, vis);
                }
            }
        }
        return count;
    }
};