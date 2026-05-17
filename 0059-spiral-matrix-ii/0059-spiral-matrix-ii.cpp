class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 1){
            return {{1}};
        }
        vector<vector<int>> res(n, vector<int> (n, 0));

        int srow = 0, erow = n-1, scol = 0, ecol = n-1;

        int num = 1;
        for(int k = 1; k < n *n; k++){
           //upper 
           for(int i = scol; i <= ecol; i++){
                res[srow][i] = num;
                num++;
           }

           //left
           for(int j = srow+1; j <= erow; j++){
                res[j][ecol] = num;
                num++;
           }

           //bottom
           for(int i = ecol-1; i >= scol; i--){
                res[erow][i] = num;
                num++;
           }

           //left
           for(int i = erow-1; i>=srow+1; i--){
                res[i][scol] = num;
                num++;
           }

           srow++; scol++; erow--; ecol--;
        }
        return res;
    }
};