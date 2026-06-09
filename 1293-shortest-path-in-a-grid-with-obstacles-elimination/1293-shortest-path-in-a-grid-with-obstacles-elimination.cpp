class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if(m == 1 && n == 1) return 0;


        vector<vector<vector<int>>> dist(m, vector<vector<int>> (n, vector<int> (k+1, INT_MAX)));

        priority_queue<pair<int, pair<int, pair<int, int>>>,
        vector<pair<int, pair<int, pair<int, int>>>>,
        greater<pair<int, pair<int, pair<int, int>>>>> pq;

        pq.push({0, {0, {0, 0}}}); // {distance, {obstacles_used, {row, col}}}

        dist[0][0][0] = 0;

        while(!pq.empty()){
            int currDist = pq.top().first;
            int currObstacle = pq.top().second.first;
            int row = pq.top().second.second.first;
            int col = pq.top().second.second.second;
            pq.pop();

            if(row == m-1 && col== n-1) return currDist;


            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i =0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >=0 && nrow < m && ncol >=0 && ncol < n){
                    
                    int Obstacle = (grid[nrow][ncol] == 1) ? 1: 0;

                    int newObstacle = currObstacle + Obstacle;
                    
                    if(newObstacle <= k && dist[nrow][ncol][newObstacle] > currDist+1){
                        pq.push({currDist+1, {newObstacle, {nrow, ncol}}});
                        dist[nrow][ncol][newObstacle] = currDist+1;
                    }
                }
            }

        }
        return -1;
    }
};