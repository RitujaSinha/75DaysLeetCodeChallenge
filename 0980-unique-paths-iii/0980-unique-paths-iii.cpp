class Solution {
public:
    int ans;
    void solve(int i, int j, vector<vector<int>>&grid, int count, int nonObstacle){
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == -1) return;

        if(grid[i][j] == 2){
            if(count== nonObstacle){
                ans++;
            }
            return;
        }

        grid[i][j] = -1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};


        for(int dir =0; dir < 4; dir++){
            int nrow = i + delrow[dir];
            int ncol = j + delcol[dir];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                solve(nrow, ncol,grid, count+1, nonObstacle);
            }
        }

        grid[i][j] = 0;

        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int nonObstacle = 0;

        int row = -1, col =-1;
        for(int i =0; i < m; i++){
            for(int j =0; j < n; j++){
                if(grid[i][j] == 0){
                    nonObstacle++;
                }
                if(grid[i][j] == 1){
                    nonObstacle++;
                    row = i;
                    col = j; 
                }
            }
        }

        int count=0;
       
        solve(row, col, grid,count, nonObstacle);

        return ans;
    }
};