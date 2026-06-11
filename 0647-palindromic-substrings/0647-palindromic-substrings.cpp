class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        vector<vector<bool>> t(n, vector<bool> (n, false));

        int cnt=0;
        for(int i =0; i < n; i++){
            t[i][i] = true;
            cnt++;
        }

        for(int L =2; L <=n; L++){
            for(int i = 0; i+L-1< n; i++){
                int j = i+L-1;

                if(i+1==j){
                    t[i][j] = (s[i]==s[j]);
                } else{
                    t[i][j] = (s[i] ==s[j] && t[i+1][j-1]);
                }

                if(t[i][j]) cnt++;
            }
        }
        return cnt;
    }
};