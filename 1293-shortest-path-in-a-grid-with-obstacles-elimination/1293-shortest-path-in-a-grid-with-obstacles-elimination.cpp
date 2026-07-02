class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int, pair<int, pair<int, int>>>,
        vector<pair<int, pair<int, pair<int, int>>>>,
        greater<pair<int, pair<int, pair<int, int>>>>> pq;

        vector<vector<vector<int>>> dis(m, vector<vector<int>> (n, vector<int> (k+1, INT_MAX)));

        pq.push({0,{0, {0, 0}}}); //steps, obstacle, row, col
        dis[0][0][0] = 0;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!pq.empty()){
            int curSteps = pq.top().first;
            int currObstacle = pq.top().second.first;
            int r = pq.top().second.second.first;
            int c = pq.top().second.second.second;
            pq.pop();

            if(currObstacle > k) continue;

            if(r == m-1 && c == n-1){
                return curSteps;
            }

            for(int i = 0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >=0 && nrow < m && ncol >=0 && ncol < n){

                    int newObstacle = currObstacle + grid[nrow][ncol];

                    if(newObstacle <= k && dis[nrow][ncol][newObstacle] > newObstacle){
                        dis[nrow][ncol][newObstacle] = newObstacle;
                        pq.push({curSteps+1,{ newObstacle,{nrow, ncol}}});
                    }
                }
            }
        }
        return -1;
    }
};