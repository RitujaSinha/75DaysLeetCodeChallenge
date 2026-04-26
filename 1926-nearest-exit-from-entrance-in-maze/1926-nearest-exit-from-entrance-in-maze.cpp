class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));

        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        vis[entrance[0]][entrance[1]] = 1;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();


            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i =0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                    if(nrow >=0 && nrow < m && ncol >=0 && ncol < n && 
                    !vis[nrow][ncol] && maze[nrow][ncol] == '.'){

                        if(nrow == 0 || ncol ==0|| nrow == m-1 || ncol == n-1) return d+1;//check boundary condition
                        else{
                    q.push({{nrow, ncol}, d+1});
                    vis[nrow][ncol] = 1;
                    }
                    }
            }
         }
        return -1;
    }
};