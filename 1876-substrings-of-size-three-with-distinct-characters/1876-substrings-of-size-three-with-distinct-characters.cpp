class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();

        unordered_map<char, int> m;

        int l=0, r= 0;
        int count =0;
        while(r< n){
            m[s[r]]++;

            if(r-l+1 > 3){
                m[s[l]]--;
                if(m[s[l]] == 0) m.erase(s[l]);
                l++;
            }

            if(r-l+1 == 3){
                if(m.size() == 3){
                    count++;
                }
            }
            r++;
        }
        return count;
    }
};