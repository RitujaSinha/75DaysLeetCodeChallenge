class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));

        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc]=1;

        int initialColor = image[sr][sc];

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            int delRow[] ={-1, 0, 1, 0};
            int delCol[] ={0, 1, 0, -1};

            for(int i =0; i < 4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initialColor && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] =1;
                    q.push({nrow, ncol});
                }
            }
            image[row][col] = color;
        }
        return image;
    }
};