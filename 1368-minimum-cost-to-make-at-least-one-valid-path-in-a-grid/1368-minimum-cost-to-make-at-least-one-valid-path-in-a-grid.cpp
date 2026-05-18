class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // pq.push({0, 0});
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, 
        greater<pair<int, pair<int,int>>>> pq;

        pq.push({0, {0, 0}});

        vector<vector<int>> cost(m, vector<int> (n, INT_MAX));   
        cost[0][0] = 0;

        int delrow[] = {0, 0, 1, -1};
        int delcol[] = {1, -1, 0, 0};

        while(!pq.empty()){
            int c = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){

                    int newCost = 0;
                    if(grid[row][col] != i+1){// different direction
                        newCost = c + 1;
                    } else{
                         newCost = c + 0;
                    }

                    if(newCost < cost[nrow][ncol]){
                        cost[nrow][ncol] = newCost;
                        pq.push({newCost, {nrow, ncol}});
                    }
                }
            }
        }
        return cost[m-1][n-1];
    }
};