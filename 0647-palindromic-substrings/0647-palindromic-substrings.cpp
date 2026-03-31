class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        vector<vector<bool>> t(n, vector<bool> (n, false));
        //State Defintion: t[i][j] = true : s[i:j] is a palindromic substring where i and j are inclusive indices

        int count =0;

        for(int L =1; L<=n; L++){
            for(int i = 0; i+L-1<n; i++){
                int j = i+L-1;

                if(i==j){
                    t[i][j] = true;
                } else if(i+1 == j){
                    t[i][j] = (s[i] == s[j]);
                } else{
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]);
                }

                if(t[i][j] == true){
                    count++;
                }
            }
        }
        return count;
    }
};