class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<bool> lower(26, false), upper(26, false);
        for(char c: word){
            if(islower(c)) lower[c-'a'] = 1;
            else upper[c-'A'] = 1;
        }

        int count =0;
        for(int i = 0; i < 26; i++){
            if(lower[i] == 1 &&  upper[i] == 1){
                count++;
            }
        }

        return count;
    }
};