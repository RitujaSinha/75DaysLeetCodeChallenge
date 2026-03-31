class Solution {
public:
     bool isPalindrome(int st, int end, string &s){
        
        while(st <= end){
            if(s[st] != s[end]) return false;
            st++; end--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n =s.size();

        int maxi = INT_MIN;
        string res = "";
        for(int i =0; i < n; i++){
            for(int j =i; j < n; j++){
                if(isPalindrome(i, j, s)){
                    if(maxi < j-i+1){
                        maxi = j-i+1;
                        res = s.substr(i, j-i+1);
                    }
                }
            }
        }
        return res;
    }
};