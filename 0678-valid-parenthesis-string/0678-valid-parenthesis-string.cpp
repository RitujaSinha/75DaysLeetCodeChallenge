class Solution {
public:
    bool solve(int i, int count, string& s,  vector<vector<int>> &dp){
        if(count < 0) return false;

        if(i >= s.size()){
            return count==0;
        }

        if(dp[i][count] != -1) return dp[i][count];

        bool ans = false;

        if(s[i] == '('){
           return ans = solve(i+1, count+1, s, dp);
        }
        else if(s[i] == ')'){
           return ans = solve(i+1, count-1, s, dp);
        } else{
            if(solve(i+1, count+1, s, dp)) ans= true;
            if(solve(i+1, count-1, s, dp)) ans= true;
            if(solve(i+1, count, s, dp)) ans= true;
        }

        return dp[i][count] = ans;
    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(101, -1));
       return solve(0, 0, s, dp);
    }
};