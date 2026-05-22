class Solution {
public:
    bool isPalindrome(int i, int j, string &s, vector<vector<int>> &t){
        if(i >= j) return true;

        if(t[i][j] != -1) return t[i][j];

        if(s[i] == s[j]){
            return t[i][j]= isPalindrome(i+1, j-1, s, t);
        }
        return t[i][j]=  false;
    }
    string longestPalindrome(string s) {
        int n = s.size();

        if(n==1) return s;

        vector<vector<int>> t(n, vector<int> (n, -1));

        int maxL = 1;
        int idx =0;
        for(int i = 0; i < n; i++){
            for(int j =i; j < n; j++){
                if(isPalindrome(i, j, s,t)){
                    if(j-i+1 > maxL){
                        maxL = j-i+1;
                        idx = i;
                    }
                }
            }
        }
        return s.substr(idx, maxL);
    }
};