class Solution {
public:
    bool find(vector<vector<char>>& grid, int i, int j, int idx, string word){
        int m = grid.size();
        int n = grid[0].size();

        if(idx == word.size()-1){
            return true;
        }

        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '$') return false;

        if(grid[i][j] != word[idx]) return false;

        char temp = grid[i][j];
        grid[i][j] = '$';

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int dir = 0; dir < 4; dir++){
            int nrow = i + delrow[dir];
            int ncol = j + delcol[dir];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                if(grid[nrow][ncol] == word[idx+1]){
                    if(find(grid, nrow, ncol, idx+1, word)) return true;
                }
            }
        } 

        grid[i][j] = temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i =0; i < m; i++){
            for(int j =0; j < n; j++){
                if(board[i][j] == word[0] && find(board, i, j,0, word)){
                    return true;
                }
            }
        }
        return false;
    }
};