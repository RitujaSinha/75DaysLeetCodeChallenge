class Solution {
public:
    bool isPalin(int i, int j, string &s){

        if(i>= j) return true;

        if(s[i] != s[j]){
            return false;
        }

        return isPalin(i+1, j-1, s);
    }
    string longestPalindrome(string s) {
        int n = s.size();

        if(n == 1) return s;

        int maxP = 1;
        int idx = -1;
        for(int i =0; i < n; i++){ 
            for(int j = i; j < n; j++){
                if(isPalin(i, j, s)){
                    if(maxP <= j-i+1){
                        maxP = j-i+1;
                        idx = i;
                    }
                }
            }
        }
        return s.substr(idx, maxP);
    }
};