class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();

        unordered_map<char, int> mpp;
        for(char &ch: s){
            mpp[ch]++;
        }

        if(mpp.size() == n) return n-1;

        sort(s.begin(), s.end());

        unordered_map<int, int> m;

        int op =0;

        int cnt = 1;
        for(int i = 1; i< n; i++){
            if(s[i] == s[i-1]){
                cnt++;
            } else{
                while(cnt > 0 && m.find(cnt) != m.end()){
                    cnt--;
                    op++;
                }
                m[cnt] = 1;
                cnt = 1;
            }
        }

        while(cnt > 0 && m.find(cnt) != m.end()){
            cnt--;
            op++;
        }
        return op;
    }
};