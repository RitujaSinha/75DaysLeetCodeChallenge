class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cost(m, vector<int> (n, INT_MAX));

        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        pq.push({0,{0, 0}}); //{cost,{row, col}}
        cost[0][0] = 0;

        while(!pq.empty()){
            int currCost = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            if(row == m-1 && col == n-1) return cost[m-1][n-1];

            if(currCost > cost[row][col]) continue;

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i =0; i < 4; i++){

                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >=0 && nrow < m && ncol>=0 && ncol < n){
                    
                    int extraCost = 1;

                    if(grid[row][col] == 1 && row == nrow && col+1 == ncol){
                        extraCost = 0;
                    } else if(grid[row][col] == 2 &&  row == nrow && col-1 == ncol){
                        extraCost  =0;
                    }  else if(grid[row][col] == 3 &&  row+1 == nrow && col == ncol){
                        extraCost  =0;
                    }  else if(grid[row][col] == 4 &&  row-1 == nrow && col == ncol){
                        extraCost  =0;
                    }

                    int newCost = extraCost + currCost;

                    if(newCost < cost[nrow][ncol]){
                        cost[nrow][ncol] = newCost;
                        pq.push({newCost,{nrow, ncol}});
                    }

                }
            }
        }
        return cost[m-1][n-1];
    }
};