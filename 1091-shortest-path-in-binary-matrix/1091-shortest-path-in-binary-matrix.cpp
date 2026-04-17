class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> vis(n, vector<int> (n, 0));

        if(grid[0][0] == 1 || grid[n-1][n-1]) return -1;

        queue<pair<pair<int, int>,int>> q;
        q.push({{0, 0},1});  
        vis[0][0] = 1;

        int delrow[] = {0,1, 1, 1, 0, -1, -1, -1};
        int delcol[] = {-1, -1, 0, 1, 1, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            
            int dist = q.front().second;
            q.pop();

            if(r == n-1 && c == n-1) return dist;
            
            for(int i =0; i < 8; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < n && grid[nrow][ncol] == 0 
                && !vis[nrow][ncol]){
                    vis[nrow][ncol] =1;
                    q.push({{nrow, ncol}, dist+1});
                }
            }
            
        }  
        return -1;
    }
};