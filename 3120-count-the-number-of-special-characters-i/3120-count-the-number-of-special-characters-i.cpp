class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        // vector<int> freq1(26), freq2(26);
        // for(char c: word){
        //     if(c>='a' && c<='z') freq1[c-'a'] = 1;
        //     else freq2[c-'a'] = 1;
        // }

        int count =0;
        // for(int i = 0; i < 26; i++){
        //     if(freq1[i] == 1 && freq2[i] == 1){
        //         count++;
        //     }
        // }
        
        unordered_map<char, int> m;
        set<char> st;
        for(char ch: word){
            m[ch]++;
            if(ch>='a' && ch<='z') st.insert(ch);
        }

        for(auto it: st){
            if(m.find(it-32) != m.end()){
                count++;
            }
        }

        return count;
    }
};