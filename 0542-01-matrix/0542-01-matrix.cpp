class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));
        vector<vector<int>> dist(m, vector<int> (n, 0));

        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i < m; i++){
            for(int j =0; j < n; j++){
                if(mat[i][j] == 0 && !vis[i][j]){
                    vis[i][j] = 1;
                    dist[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        }


        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            int delrow[] ={-1, 0, 1, 0};
            int delcol[] ={0, 1, 0, -1};

            for(int i =0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];


                if(nrow >=0 && nrow< m && ncol >=0 && ncol< n && !vis[nrow][ncol] 
                && mat[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, d+1});
                    dist[nrow][ncol] = d+1;
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return dist;
    }
};