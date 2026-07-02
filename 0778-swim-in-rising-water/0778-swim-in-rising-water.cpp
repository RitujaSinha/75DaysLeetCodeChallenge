class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        

        vector<vector<int>> minTime(n, vector<int> (n, INT_MAX));

        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0],{0, 0}});
        minTime[0][0] = grid[0][0];

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!pq.empty()){
            int time = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(time > minTime[r][c]) continue;

            if(r == n-1 && c == n-1) return time;

            for(int i =0; i <4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >=0 && ncol < n && ncol >=0 && nrow < n){

                    int newTime =max(time, grid[nrow][ncol]);

                    if(newTime < minTime[nrow][ncol]){
                        minTime[nrow][ncol] = newTime;
                        pq.push({newTime, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};