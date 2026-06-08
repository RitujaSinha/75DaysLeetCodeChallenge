class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int> (n, INT_MAX));

        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            int currCost = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i =0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >=0 && nrow < m && ncol >=0 && ncol < n){

                    int extraCost = 1;
                    
                    if(grid[row][col] == 1 && row == nrow && ncol == col+1){
                        extraCost =0; //right
                    }

                    if(grid[row][col] == 2 && row == nrow && ncol == col-1){
                        extraCost =0; //left
                    }

                    if(grid[row][col] == 3 && row+1 == nrow && ncol == col){
                        extraCost =0; //lower
                    }
                    if(grid[row][col] == 4 && row-1 == nrow && ncol == col){
                        extraCost =0; //upper
                    }

                    int newCost = extraCost + currCost;

                    if(newCost < dist[nrow][ncol]){
                        dist[nrow][ncol] = newCost;
                        pq.push({newCost, {nrow, ncol}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};