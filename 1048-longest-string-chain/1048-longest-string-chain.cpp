class Solution {
public:
    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }

    bool predecessor(string &s1, string &s2){
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1 !=  n2+1) return false;

        int i =0, j =0;
        while(i < n1 && j < n2){
            if(s1[i] != s2[j]){
                i++;
            } else{
                i++;
                j++;
            }
        }

        return j == n2;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), comp);

        vector<int> t(n, 1);

        int maxChain =1;
        for(int i =0; i < n; i++){
            for(int j =0; j < i; j++){
                if(predecessor(words[i], words[j])){
                    t[i] = max(t[i] , t[j]+1);
                    maxChain = max(maxChain, t[i]);
                }
            }
        }
        return maxChain;
    }
};