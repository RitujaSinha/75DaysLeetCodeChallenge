class Solution {
public:
    int ans = 0;

    void solve(int idx, int n, string &temp, string &vowels){
        if(n ==0){
            ans++;
            return;
        }

        if(idx == vowels.size()){
            return;
        }

        for(int i = idx; i < vowels.size(); i++){
            temp.push_back(vowels[i]);
            solve(i, n-1, temp, vowels);
            temp.pop_back();
        }
    }
    int countVowelStrings(int n) {
        
        string vowels = "aeiou";
        string temp = "";
        solve(0, n, temp, vowels);

        return ans;
    }
};