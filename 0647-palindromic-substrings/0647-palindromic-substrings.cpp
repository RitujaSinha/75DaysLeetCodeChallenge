class Solution {
public:
    bool isPalindrome(int st, int end, string &s){
        
        while(st <= end){
            if(s[st] != s[end]) return false;
            st++; end--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int cnt =0;

        for(int i =0; i < n; i++){
            for(int j =i; j < n; j++){
                if(isPalindrome(i, j, s)) cnt++;
            }
        }
        return cnt;
    }
};