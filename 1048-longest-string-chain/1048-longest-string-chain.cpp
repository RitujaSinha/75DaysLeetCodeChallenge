class Solution {
public:
    static bool comp(string &a, string &b){
        return a.size() < b.size();
    }

    bool isPred(string &prev, string &curr){
        int m = prev.size();
        int n = curr.size();

        if(n != m+1) return false;

        int i = m-1, j=n-1;
        while(i>=0 && j>=0){
            if(prev[i] == curr[j]){
                i--; j--;
            } else{
                j--;
            }
        }
        return i < 0;
    }

    int solve(int i,int P, vector<string>& words, vector<vector<int>> &t){
        if(i == words.size()){
            return 0;
        }

        if(t[i][P+1] !=-1) return t[i][P+1]; 


        int take = 0;
        if(P== -1 || isPred(words[P], words[i])){
            take = 1 + solve(i+1, i, words, t);
        }
        int notTake = solve(i+1, P, words, t);

        return t[i][P+1] = max(take, notTake);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), comp);

        vector<vector<int>> t(n, vector<int> (n+1, -1));

        return solve(0,-1, words, t);
    }
};