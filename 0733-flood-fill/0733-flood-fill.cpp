class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color, 
    vector<vector<int>> &result){
        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        int oldColor = image[sr][sc]; 

        q.push({sr, sc});

        result[sr][sc] = color;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int r = it.first;
            int c =it.second;

            //up
            if(r-1 >= 0 && result[r-1][c] == oldColor){
                result[r-1][c] = color;
                q.push({r-1,c});
            }

            //left
            if(c-1 >=0 && result[r][c-1] == oldColor){
                result[r][c-1] = color;
                q.push({r,c-1});
            }

            //down
            if(r+1 < n && result[r+1][c] ==oldColor){
                result[r+1][c] = color;
                q.push({r+1,c});
            }

            //right
            if(c+1 < m && result[r][c+1] == oldColor){
                result[r][c+1] = color;
                q.push({r,c+1});
            }

        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        if(image[sr][sc] == color) return image; 

        vector<vector<int>> result = image;

        bfs(image, sr, sc, color, result);
        return result;
    }
};