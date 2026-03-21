class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int i =x, j = x+k-1;
        int col =y;
        int cnt =0;
        while(i< j){
            swap(grid[i][col], grid[j][col]);
            cnt++;
            col++;
            if(cnt == k){
                i++; j--;
                cnt=0;
                col = y;
            }
        }

        return grid;
    }
};