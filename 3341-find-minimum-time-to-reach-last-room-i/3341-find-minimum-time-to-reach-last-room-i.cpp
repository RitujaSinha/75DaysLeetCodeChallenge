class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}}); //time, row, col

        vector<vector<int>> minTime(n, vector<int> (m, INT_MAX));
        minTime[0][0] = 0;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!pq.empty()){
            int currTime = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(currTime > minTime[r][c]) continue;

            if(r == n-1 && c == m-1){
                return currTime;
            }

            for(int i = 0; i < 4; i++){

                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m){

                    int newTime = 1 + max(moveTime[nrow][ncol],currTime); // need to revise this

                    if(newTime < minTime[nrow][ncol]){
                        minTime[nrow][ncol] = newTime;
                        pq.push({newTime, {nrow, ncol}});
                    }
                }
            }
        }
        return minTime[n-1][m-1];
    }
};