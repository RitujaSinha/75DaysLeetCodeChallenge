class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> dis(m, vector<int> (n, INT_MAX));

        if(grid[0][0] == 1){
            pq.push({1,{0, 0}});
        } else{
            pq.push({0,{0, 0}});
        }

        dis[0][0] = grid[0][0];


        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!pq.empty()){
            int currObstacle = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(currObstacle > dis[r][c]) continue;

            if(r ==m-1 && c == n-1) return dis[r][c];

            for(int i = 0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >=0 && nrow < m && ncol >=0 && ncol < n){

                    int obstacle = grid[nrow][ncol];

                    int newObstacle = currObstacle + obstacle;

                    if(newObstacle < dis[nrow][ncol]){
                        pq.push({newObstacle,{nrow, ncol}});
                        dis[nrow][ncol] = newObstacle;
                    }
                }
            }
        }
        return -1;
    }
};