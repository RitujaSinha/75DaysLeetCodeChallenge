class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();

        // vector<int> vis(m,0);

        // int maxi = INT_MIN, mini = INT_MAX;
        // int idxMx = -1, idxMn =-1;
        // for(int i = 0; i < m; i++){
        //     for(int j =0; j < n; j++){
        //         if(maxi < units[i][j]){
        //             maxi = units[i][j];
        //             idxMx= i;
        //         }

        //         if(mini > units[i][j]){
        //             mini = units[i][j];
        //             idxMn = i;
        //         }
        //     }
        // }

        long long ans =0;
        if(n== 1){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    ans += units[i][j];
                }
            }
            return ans;
        }

        // int result  =0;
        // for(int i = 0; i < m; i++){
        //     // if(idxMx == idxMn){
        //     //     // result += units[i][1];
        //     //     // if(i+1 < m) units[i+1][0] = mini;
        //     //     // idxMx = idxMn = -1;
        //     //     // continue;
        //     //     result += mini;
        //     //     result += maxi;
        //     //     i++;
        //     //     continue;
        //     // }
        //     // if(i == idxMx){
                
        //     //     result += units[i][1];
        //     //     continue;
        //     // }

        //     if(units[i][0] <= units[i][1]){
        //         units[idxMn][0] = units[i][0];
        //         result += units[i][1];
        //     } else{
        //         result += units[i][0];
        //     }
        // }

         for(int i = 0; i < m; i++){
            sort(units[i].begin(), units[i].end());
        }

        ans = 0;
        for(int i = 0; i < m; i++){
            ans += units[i][1];
        }

        int mini = INT_MAX, minSec =INT_MAX;
        for(int i = 0; i < m; i++){
            if(minSec > units[i][1]){
                minSec= units[i][1];
            }
            mini = min(mini, units[i][0]);
        }

        

        // ans -= units[minSecIdx][1];

        return ans-minSec+mini;
    }
};