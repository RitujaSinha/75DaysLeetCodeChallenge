class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int, pair<int,pair<int, int>>>, 
        vector<pair<int, pair<int,pair<int, int>>>>,
        greater<pair<int, pair<int,pair<int, int>>>>> pq;

        pq.push({0,{0, {0, 0}}});//{steps,{k{row, col}}}

        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(k+1, INT_MAX)));
        dist[0][0][0] = 0;


        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!pq.empty()){
            int steps = pq.top().first;
            int obstacles = pq.top().second.first;
            int row = pq.top().second.second.first;
            int col = pq.top().second.second.second;
            pq.pop();
            if(steps > dist[row][col][obstacles]) continue;

            if(obstacles > k) continue;

            if(row == m-1 && col == n-1) return steps;

            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                    
                    int newObstacle = obstacles + grid[nrow][ncol];
                    
                    if(newObstacle <= k && dist[nrow][ncol][obstacles] > steps+1){
                        dist[nrow][ncol][obstacles] = steps+1;
                        pq.push({steps+1,{newObstacle,{nrow, ncol}}});
                    }
                }
            }
        }
        return -1;
    }
};