class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.size();

        vector<vector<bool>> t(n, vector<bool> (n, false));

        int maxL =1, sp =0;

        for(int L = 1; L<=n; L++){
            for(int i =0; i+L-1 < n; i++){
                int j= i+L-1;

                if(L == 1){
                    t[i][j] = 1;
                } else if(s[i]==s[j] && L==2){
                    t[i][j] = (s[i]== s[j]);
                    maxL =2;
                    sp =i;
                } else if(s[i] == s[j] && t[i+1][j-1]){
                    t[i][j]=1;

                    if(j-i+1 > maxL){
                        maxL = j-i+1;
                        sp = i;
                    } 
                } else{
                    t[i][j]= 0;
                }
            }
        }
        return s.substr(sp, maxL);
    }
};