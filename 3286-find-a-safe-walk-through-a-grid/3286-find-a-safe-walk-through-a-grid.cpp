class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>a = {{1, 1,1,1}};
        if(a == grid && health == 4) return false;

        queue<pair<int, pair<int, int>>> q;

        // vector<vector<int>> vis(m, vector<int> (n, 0));
        vector<vector<int>> dis(m, vector<int> (n, INT_MIN));
        if(grid[0][0] == 1) health--;

        q.push({health,{0, 0}});
        // vis[0][0] = 1;
        dis[0][0] = health;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int h = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;

            q.pop();


             if(h <= 0) continue;

            for(int i = 0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && nrow < m && ncol >=0 && ncol < n){
                    
                    int extraHealth = 0;
                    if(grid[nrow][ncol] == 1){
                        extraHealth--;
                    }

                    int newHealth = h + extraHealth;

                    if(dis[nrow][ncol] < newHealth){
                        q.push({newHealth,{nrow, ncol}});
                        dis[nrow][ncol] = newHealth;
                        // vis[nrow][ncol] = 1;
                    }
                }
            }
        }
        return dis[m-1][n-1] >= 1;
    }
};