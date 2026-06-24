class Solution {
public:
    void solve(int i, vector<string> &ans, string &temp, string &digits, unordered_map<char, string> &mpp){
        if(i == digits.size()){
            ans.push_back(temp);
            return;
        }

        for(auto it: mpp[digits[i]]){
            temp.push_back(it);
            solve(i+1, ans, temp, digits, mpp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        vector<string> ans;
        string temp = "";
        solve(0, ans, temp, digits, mpp);
        return ans;
    }
};