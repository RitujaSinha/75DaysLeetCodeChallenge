class Solution {
public:
    bool isUnique(string &s){
        vector<int> freq(26, 0);

        for(char c: s){
            if(freq[c-'a'] > 0) return false;
            freq[c-'a']++;
        }
        return true;
    }
    int solve(int i, int ans, string &temp, vector<string>& arr){
        if(!isUnique(temp)) return ans;

        if(i == arr.size()){
            ans = max(ans, (int)temp.size());
            return ans;
        }

        temp += arr[i];
        ans = solve(i+1, ans, temp, arr);
        for(int k = 0; k < arr[i].size(); k++){
            temp.pop_back();
        }
        ans = solve(i+1, ans, temp, arr);

        return ans;
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();

        int ans=0;
        string temp = "";

        return solve(0, ans, temp, arr);
    }
};