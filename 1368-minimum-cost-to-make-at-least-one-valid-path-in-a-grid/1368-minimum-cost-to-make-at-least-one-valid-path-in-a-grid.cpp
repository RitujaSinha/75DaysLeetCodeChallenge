class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}}); //cost, row, col

        vector<vector<int>> cost(m, vector<int> (n, INT_MAX));

        cost[0][0] = 0; 

        while(!pq.empty()){
            int currCost = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            if(row == m-1 && col == n-1) return currCost;

            if(cost[row][col] < currCost) continue;

            int delrow[] = {0,0, 1, -1};
            int delcol[] = {1, -1, 0, 0};

            for(int i =0; i < 4; i++){
                int nrow =  row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >=0 && nrow < m && ncol>=0 && ncol < n){

                    int extraCost = 0;
                    if(grid[row][col]-1 != i){
                        extraCost +=1;
                    }

                    int newCost = currCost + extraCost;

                    if(cost[nrow][ncol] > newCost){
                        cost[nrow][ncol] = newCost;
                        pq.push({newCost, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};