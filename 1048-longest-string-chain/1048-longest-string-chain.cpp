class Solution {
public:
    static bool comp(string &a, string &b){
        return a.size() < b.size();
    }

    bool isPred(string &curr, string &prev){
        int m = curr.size();
        int n = prev.size();

        if(m != n+1) return false;

        int i = m-1, j=n-1;

        while(j >= 0 && i >=0){
            if(curr[i] == prev[j]){
                i--; j--;
            } else{
                i--;
            }
        }
        return j < 0;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if(n==1) return 1;

        sort(words.begin(), words.end(), comp);

        vector<int> t(n, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isPred(words[i], words[j])){
                    t[i] = max(t[i], t[j]+1);
                }
            }
        }
        return *max_element(t.begin(), t.end());
    }
};