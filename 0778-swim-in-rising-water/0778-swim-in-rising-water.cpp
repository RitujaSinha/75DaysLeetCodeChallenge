class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));

        q.push({{0, 0}, grid[0][0]});
        dist[0][0] = grid[0][0];

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            q.pop();

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i =0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n){
                    int newTime = max(time, grid[nrow][ncol]);

                    if(newTime < dist[nrow][ncol]){
                        dist[nrow][ncol] = newTime;
                        q.push({{nrow, ncol}, newTime});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};