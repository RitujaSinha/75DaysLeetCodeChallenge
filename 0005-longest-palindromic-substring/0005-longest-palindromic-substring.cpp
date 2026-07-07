class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<bool>> t(n+1, vector<bool> (n+1, false));

        int maxL = 1;
        int idx = -1;
        for(int i = 0; i < n; i++){
            t[i][i] = true;
            idx = i;
        }

        for(int L = 2; L<=n; L++){
            for(int i = 0; i + L-1 < n; i++){
                int j = i+L-1;

                if(i+1 == j){
                    t[i][j] = (s[i] == s[j]);
                } else{
                    t[i][j] = (s[i]==s[j] && t[i+1][j-1]);
                }

                if(t[i][j]){
                    if(maxL < j-i+1){
                        maxL = j-i+1;
                        idx = i;
                    }
                }
            }
        }
        return s.substr(idx, maxL);
    }
};