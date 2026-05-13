class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int> (n, INT_MAX));

        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
        pq.push({{0, 0}, 0}); //{{row, col}, cost}
        dist[0][0] = 0;

        int delrow[] = {0, 0, 1, -1}; //right, left, lower, upper
        int delcol[] = {1, -1, 0, 0};

        int cost  = 0;
        while(!pq.empty()){
            int row = pq.top().first.first;
            int col = pq.top().first.second;
            int cost = pq.top().second;
            pq.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n){

                    int newCost = 0;
                    if(grid[row][col] == i+1){ //same direction
                        newCost = cost + 0;
                    } else{
                        newCost = cost + 1;
                    }

                    if(newCost < dist[nrow][ncol]){
                        dist[nrow][ncol] = newCost;
                        pq.push({{nrow, ncol}, newCost});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};