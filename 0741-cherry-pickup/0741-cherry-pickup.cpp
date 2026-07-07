class Solution {
public:
    int n;
    int t[51][51][51][51];
    int neg = -1e8;
    int solve(int r1, int c1, int r2, int c2, vector<vector<int>>& grid){
        if(r1 >= n || c1 >= n|| r2 >= n || c2 >= n) return neg;

        if(grid[r1][c1] == -1 || grid[r2][c2] == -1){
            return neg;
        } 

        if(r1 == n-1 && c1 == n-1 && r2 == n-1 && c2 == n-1){
            return grid[r1][c1];
        }

        if(t[r1][c1][r2][c2] != -1){
            return t[r1][c1][r2][c2];
        }

        int cherry = 0;
        if(r1 == r2 && c1==c2){
            cherry += grid[r1][c1];
        } else{
            cherry += grid[r1][c1];
            cherry += grid[r2][c2];
        }

        int p1 = solve(r1, c1 + 1, r2+1, c2, grid);
        int p2 = solve(r1+1,c1, r2+1, c2, grid);
        int p3 = solve(r1, c1+1, r2, c2+1, grid);
        int p4  = solve(r1+1, c1, r2, c2+1, grid);

        return t[r1][c1][r2][c2] = cherry + max(max(p3, p2), max(p1, p4));
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();

        memset(t, -1, sizeof(t));

        int ans=  solve(0, 0, 0, 0 , grid);

        return max(ans, 0);
    }
};