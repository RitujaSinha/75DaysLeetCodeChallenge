class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if(n==1) return s;

        vector<vector<bool>> t(n, vector<bool> (n, false));

          int idx = -1;
        for(int i = 0; i < n; i++){
            t[i][i] = true;
            idx=i;

        }

        int maxL = 1;
        for(int L =2; L<= n; L++){
            for(int i = 0; i + L-1< n; i++){
                int j =i+L-1;

                if(i+1 == j && L==2){
                    t[i][j] = (s[i]==s[j]);

                    if(t[i][j]){
                        maxL = j-i+1;
                        idx = i;
                    }
                } else if(s[i]==s[j] && t[i+1][j-1]){
                    t[i][j] = (s[i]==s[j] && t[i+1][j-1]);
                    if(t[i][j]){
                        maxL = j-i+1;
                        idx = i;
                    }
                }
            }
        }
        return s.substr(idx, maxL);
    }
};