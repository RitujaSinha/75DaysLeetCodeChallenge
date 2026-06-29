class Solution {
public:
    // bool isSubString(string &s, string &word){
    //     int i = 0, j =0;

    //     while(i < s.size() && j < word.size()){
    //         if(s[i] == word[j]){
    //             i++;
    //         }
    //         j++;
    //     }
    //     return i == s.size();
    // }
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();

        int cnt = 0;
        for(int i =0; i < n; i++){
             //if(isSubString(patterns[i], word)) cnt++;
            if(word.find(patterns[i]) != -1) cnt++;
        }
        return cnt;
    }
};