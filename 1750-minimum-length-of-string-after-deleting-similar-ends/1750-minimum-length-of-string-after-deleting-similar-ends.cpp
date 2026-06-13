class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();

        if(n==1) return 1;

        int i = 0, j = n-1;

        vector<int> freq(26, 0);
        for(char &c: s){
            freq[c-'a']++;
        }
        int cnt=0;
        for(int i =0; i < 26; i++){
            if(freq[i] > 0) cnt++;
        }
        if(cnt ==1) return 0;

        char ch;
        while(i <= j){
            if(i == j) return 1;
            if(i != 0){
                while(s[i] == ch) i++;
                while(s[j] == ch) j--;
            }
            
            if(i==0){
                ch = s[i];
            }

            if(i !=j && s[i] == s[j]){
                ch = s[i];
                i++; j--;
            } else{
                return j-i+1;
            }
        }
        
        return 0;
    }
};