class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));

        queue<pair<int, pair<int, int>>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({0, {i, j}});
                    vis[i][j] = 0;
                }
            }
        }
        
        int time= 0;

        while(!q.empty()){
            int t = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            time = max(t, time);

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1
                && !vis[nrow][ncol]){
                    q.push({t+1, {nrow, ncol}});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return time;
    }
};