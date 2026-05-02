class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> dist(m, vector<int> (n, INT_MAX));
        q.push({{0, 0}, 0});
        dist[0][0] = 0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int diff = q.front().second;
            q.pop();

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i =0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                    int newEffort = max(diff, abs(heights[nrow][ncol] - heights[r][c]));

                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        q.push({{nrow, ncol}, newEffort});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};