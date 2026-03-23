class Solution {
public:
using ll = long long;
    const long long mod = 1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        
        vector<vector<long long>> temp(m, vector<ll> (n));
        vector<vector<ll>> temp1(m, vector<ll> (n));

        //[0][0]-> cell
        temp[0][0] = grid[0][0];

        //fill 1st row
        for(ll i =1; i < n; i++){
            temp[0][i] = (grid[0][i] * temp[0][i-1]);
        }

        //fill 1st col
        for(ll j =1; j < m; j++){
            temp[j][0] = (grid[j][0] * temp[j-1][0]) ;
        }

          //[0][0]-> cell
        temp1[0][0] = grid[0][0];

        //fill 1st row
        for(ll i =1; i < n; i++){
            temp1[0][i] = (grid[0][i] * temp1[0][i-1]) ;
        }

        //fill 1st col
        for(ll j =1; j < m; j++){
            temp1[j][0] = (grid[j][0] * temp1[j-1][0]);
        }

        for(ll i =1; i < m; i++){
            for(ll j =1; j < n; j++){
    
                temp[i][j] = (max({grid[i][j] *temp[i-1][j],grid[i][j]* temp[i][j-1],grid[i][j] * temp1[i-1][j], grid[i][j]* temp1[i][j-1]}));

                temp1[i][j] = (min({grid[i][j] *temp[i-1][j],grid[i][j]* temp[i][j-1],grid[i][j] * temp1[i-1][j], grid[i][j]* temp1[i][j-1]})) ;
            }
        }


        if(temp[m-1][n-1] < 0 && temp1[m-1][n-1] < 0) return -1;
        return (max(temp[m-1][n-1], temp1[m-1][n-1])) % mod;
    }
};