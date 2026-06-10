class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans;
        if(m == 1 || n==1){
            for(int i =0; i < m; i++){
                for(int j =0; j < n; j++){
                    ans.push_back(mat[i][j]);
                }
            }
            return ans;
        }

        int col = 0;
        while(col < n){
            int c = col;
            vector<int> temp;
            for(int row = 0; row < m && c >= 0; row++){
                temp.push_back(mat[row][c]);
                c--;
            }

            if(col % 2 == 0){
                reverse(temp.begin(), temp.end());
                for(int i =0; i < temp.size(); i++){
                    ans.push_back(temp[i]);
                }
            } else{
                for(int i =0; i < temp.size(); i++){
                    ans.push_back(temp[i]);
                }
            }
            col++;
        }

        int row = 1;

        while(row < m){
            int r = row;
            vector<int> temp;
            for(col = n-1; col >= 0 && r < m; col--){
                temp.push_back(mat[r][col]);
                r++;
            }

            if((row + n - 1) % 2 == 0){
                reverse(temp.begin(), temp.end());
                for(int i = 0; i < temp.size(); i++){
                    ans.push_back(temp[i]);
                }
            } else{
                for(int i = 0; i < temp.size(); i++){
                    ans.push_back(temp[i]);
                }
            }
            row++;
        }


        return ans;
    }
};