class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || j < 0 || i>= m || j >= n || grid[i][j] == 0) return INT_MIN;
        
    
        int temp =  grid[i][j];
        grid[i][j] = 0;


        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        int ans =0;

        for(int dir = 0; dir < 4; dir++){
            int nrow = i + delrow[dir];
            int ncol = j + delcol[dir];

            if(nrow >=0 && ncol >=0 && nrow < m && ncol < n && grid[nrow][ncol] != 0){
                ans = max(ans, solve(nrow, ncol, grid));
            } 
        }

        grid[i][j] = temp;

        return temp + ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();


        int maxAns =0;
        for(int i =0; i < m; i++){
            for(int j =0; j < n; j++){
                if(grid[i][j] != 0){
                    maxAns = max(maxAns, solve(i, j, grid));
                }
            }
        }
        return maxAns;
    }
};