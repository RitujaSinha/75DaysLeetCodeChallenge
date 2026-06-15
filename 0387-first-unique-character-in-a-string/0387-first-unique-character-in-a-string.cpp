class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();

        for(int i = 0; i < n; i++){
            bool ok = false;
            for(int j =0; j < n; j++){
                if(i == j) continue;

                if(s[i] == s[j]){
                    ok = true;
                    break;
                }
            }
            if(!ok) return i;
        }
        return -1;
    }
};


