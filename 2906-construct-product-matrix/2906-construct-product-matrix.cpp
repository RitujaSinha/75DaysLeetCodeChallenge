class Solution {
public:
    const int mod = 12345;
    
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> arr;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                arr.push_back(grid[i][j] % mod);
            }
        }

        int size = arr.size();

        vector<int> prefix(size);
        prefix[0] = 1;
        for(int i = 1; i < size; i++){
            prefix[i] = (prefix[i-1] * arr[i-1]) % mod;
        }

        vector<int> suffix(size);
        suffix[size-1] = 1;
        for(int i = size-2; i >= 0; i--){
            suffix[i] = (suffix[i+1] * arr[i+1]) % mod;
        }

        vector<vector<int>> result(n, vector<int>(m));
        int k = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                result[i][j] = (prefix[k] * suffix[k]) % mod;
                k++;
            }
        }

        return result;
    }
};