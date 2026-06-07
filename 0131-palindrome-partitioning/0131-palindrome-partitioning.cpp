class Solution {
public:
    void solve(int i, vector<vector<string>> &ans, vector<string> &part, vector<vector<bool>> &t, string &s){
        if(i==s.size()){
            ans.push_back(part);
            return;
        }


        for(int j = i; j < s.size(); j++){
            if(t[i][j] == true){
                part.push_back(s.substr(i, j-i+1));
                solve(j+1,ans,part, t, s);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<bool>> t(n, vector<bool> (n, false));

        for(int i = 0; i < n; i++){
            t[i][i] = true;
        }

        for(int L = 2; L <= n; L++){
            for(int i = 0; i +L-1 < n; i++){
                int j = i+L-1;

                if(i+1==j){ //2 size palindrome
                    t[i][j] = (s[i]==s[j]);
                } else{
                    t[i][j] = (s[i]==s[j] && t[i+1][j-1]);
                }
            }
        }

        vector<vector<string>> ans;
        vector<string> part;
        solve(0,ans,part, t, s);
        return ans;
    }
};