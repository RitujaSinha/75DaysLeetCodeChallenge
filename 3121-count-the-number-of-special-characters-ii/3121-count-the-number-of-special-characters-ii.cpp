class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();

        vector<int> lower(26, -1), upper(26, -1);

        for(int i = 0; i < n; i++){
            if(islower(word[i])) lower[word[i]-'a'] = i;
            else{
                if(upper[word[i]-'A'] > -1) continue;
                upper[word[i]-'A'] = i;
            }
        }

        cout << upper[2] << endl;

        int cnt=0;
        for(int i = 0; i< 26; i++){
            if(lower[i] == -1 || upper[i] == -1) continue;

            if(lower[i] < upper[i]) cnt++;
        }
        return cnt;
    }
};