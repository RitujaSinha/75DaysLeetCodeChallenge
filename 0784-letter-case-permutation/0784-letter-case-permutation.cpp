class Solution {
public:
    void solve(int i, string &s, vector<string> &res, string &temp){
        if(i == s.size()){
            res.push_back(temp);
            return;
        }

        if(s[i] >='a' && s[i] <='z'){
            temp.push_back(s[i]);
            solve(i+1, s, res, temp);
            temp.pop_back();

            temp.push_back(s[i]-32);
            solve(i+1, s, res, temp);
            temp.pop_back();

        } else if(s[i] >= 'A' && s[i] <= 'Z'){
            temp.push_back(s[i]);
            solve(i+1, s, res, temp);
            temp.pop_back();

            temp.push_back(s[i]+32);
            solve(i+1, s, res, temp);
            temp.pop_back();
        } else{
            temp.push_back(s[i]);
            solve(i+1, s, res, temp);
            temp.pop_back();
        }
        return;
    }
    vector<string> letterCasePermutation(string s) {
        int n = s.size();

        vector<string> res;
        string temp = "";
        solve(0,s, res, temp);

        return res;
    }
};