class Solution {
public:
    bool isPalindrome(int i, int j, string &s, vector<vector<int>> &t){
        int n = s.size();

        if(i > j) return true;

        if(t[i][j] != -1) return t[i][j];

        if(s[i] == s[j]){
            return t[i][j] = isPalindrome(i+1, j-1, s, t);
        }
        return t[i][j] = false;
    }
    int countSubstrings(string s) {
        int n = s.size();

        vector<vector<int>> t(n, vector<int> (n, -1));

        int count=0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome(i, j, s, t)){
                    count++;
                }
            }
        }
        return count;
    }
};