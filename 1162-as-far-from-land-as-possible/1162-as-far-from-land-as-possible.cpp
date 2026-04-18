class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int> (n, 0));
        vector<vector<int>> vis(n, vector<int> (n, 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i =0; i < n; i++){
            for(int j =0; j <n; j++){
                if(grid[i][j] == 1){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        if(q.empty() || (q.size() == n*n)){
            return -1;
        }


        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;

            int dis = q.front().second;
            q.pop();

            dist[r][c] = dis;

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i =0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol =  c + delcol[i];

                if(nrow >= 0 && nrow < n && ncol>=0 && ncol < n && grid[nrow][ncol] == 0 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, dis+1});
                }
            }
        }

        int maxDist =0;
        for(int i =0; i < n; i++){
            for(int j =0; j < n; j++){
                maxDist = max(maxDist, dist[i][j]);
            }
        }
        return maxDist;
    }
};