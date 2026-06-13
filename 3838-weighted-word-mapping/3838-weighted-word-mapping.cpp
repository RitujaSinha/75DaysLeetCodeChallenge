class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();

        unordered_map<char, int> alpha;
        string alphabets = "abcdefghijklmnopqrstuvwxyz";

        for(int i = 0; i < 26; i++){
            alpha[alphabets[i]] = weights[i];
        }

        string result = "";
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < words[i].size(); j++){
                char ch =  words[i][j];

                sum += alpha[ch];
            }

            int cnt =0;
            for(int k = alphabets.size()-1; k>=0; k--){
                if(sum % 26 == cnt){
                    result += alphabets[k];
                }
                cnt++;
            }
        }
        return result;
    }
};