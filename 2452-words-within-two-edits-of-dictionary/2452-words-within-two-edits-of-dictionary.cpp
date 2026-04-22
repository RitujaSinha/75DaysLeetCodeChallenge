class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n1 = queries.size();
        int n2= dictionary.size();

        vector<string> result;
        for(int i =0; i < n1; i++){
            string word1 = queries[i];
            for(int j =0; j < n2; j++){
                string word2= dictionary[j];
                int cnt =0;
                for(int k =0; k < word1.size(); k++){
                    if(word1[k] != word2[k]) cnt++;
                }
                if(cnt <= 2){
                    result.push_back(word1);
                    break;
                }
            }
        }
        return result;
    }
};