class Solution {
public:
    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }

    bool isPred(string &s1, string &s2){
        int n = s1.size();
        int m = s2.size();

        if(n != m+1) return false;

        int i=0, j=0;
        while(i < n && j < m){
            if(s1[i] == s2[j]){
                j++;
            }
            i++;
        }
        return j == m;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), comp);

        vector<int> t(n, 1);

        int maxL = 1;

        for(int i =0; i < n; i++){
            for(int j =0; j < i; j++){
                if(isPred(words[i], words[j])){
                    t[i] = max(t[i], t[j]+1);
                    maxL = max(maxL, t[i]);
                }
            }
        }
        return maxL;
    }
};