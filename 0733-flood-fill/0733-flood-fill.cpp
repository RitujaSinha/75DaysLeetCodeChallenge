class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> vis(m, vector<int> (n, 0));
        vector<vector<int>> res = image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;

        int initialColor = image[sr][sc];
        res[sr][sc] = color;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];


                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && 
                image[nrow][ncol] == initialColor && !vis[nrow][ncol]){
                    res[nrow][ncol] = color;
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }


        return res;
    }
};