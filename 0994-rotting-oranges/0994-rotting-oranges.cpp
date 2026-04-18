class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i =0; i < m; i++){
            for(int j =0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int time = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;

            int t = q.front().second;

            time = max(time, t);

            q.pop();

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i =0; i < 4; i++){

                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow < m && ncol >=0 && ncol < n && grid[nrow][ncol] == 1
                && !vis[nrow][ncol]){
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        for(int i =0; i < m; i++){
            for(int j =0; j < n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        return time;
    }
};