class Solution {
public:
    int solve(int i, int j, string &word1, string &word2,  vector<vector<int>> &t){
        int n = word1.size();
        int m = word2.size();


        if(i == word1.size()){
            return m-j;
        } else if(j == word2.size()){
            return n-i;
        }

        if(t[i][j] != -1) return t[i][j];

        if(word1[i] == word2[j]){
            return t[i][j] = solve(i+1, j+1, word1, word2, t);
        }

        int insert = 1 + solve(i, j+1, word1, word2, t);
        int del = 1 + solve(i+1, j, word1, word2, t);
        int replace = 1 + solve(i+1, j+1, word1, word2, t);

        return t[i][j] = min({insert, del, replace});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> t(n, vector<int> (m, -1));
        return solve(0, 0, word1, word2, t);
    }
};