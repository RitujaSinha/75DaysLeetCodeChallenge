class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>> &res,
    int initialColor){
        int n = image.size();
        int m = image[0].size();

        // int initialColor = image[sr][sc];
        res[sr][sc] = color;

        //up
        if(sr-1>=0 && res[sr-1][sc] == initialColor){
            dfs(image, sr-1, sc, color, res, initialColor);
        }

        //right
        if(sc+1 < m && res[sr][sc+1] == initialColor){
            dfs(image, sr, sc+1, color, res, initialColor);
        }

        //left
        if(sc-1 >= 0 && res[sr][sc-1] == initialColor){
            dfs(image, sr, sc-1, color, res, initialColor);
        }

        //down
        if(sr+1 < n && res[sr+1][sc] == initialColor){
            dfs(image, sr+1, sc, color, res, initialColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>> res = image;

        int initialColor = image[sr][sc];

        if(initialColor == color) return res;

        dfs(image, sr, sc, color, res, initialColor);
        return res;
    }
};