class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int> (k+1, INT_MAX)));

        queue<pair<int, pair<int, pair<int, int>>>> q;
        q.push({0, {0, {0, 0}}});
        dist[0][0][0] = 0;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int steps = q.front().first;
            int obstacles = q.front().second.first;
            int row = q.front().second.second.first;
            int col = q.front().second.second.second;
            q.pop();

            if(row == m-1 && col == n-1) return steps;

            if(obstacles > k) continue;

            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){

                    int newObstacle = obstacles + grid[nrow][ncol];

                    if(newObstacle <= k  && steps+1 < dist[nrow][ncol][newObstacle]){
                        dist[nrow][ncol][newObstacle]= steps+1;
                        q.push({steps+1, {newObstacle,{ nrow, ncol}}});
                    }
                }
            }
        }
        return -1;
    }
};