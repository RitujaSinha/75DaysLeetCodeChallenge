class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.size();

        unordered_map<char, int> m;

        int l=0, r=0;
        int maxLen = 0;

        while(r< n){

            while(m.find(s[r]) != m.end()){
                m[s[l]]--;
                if(m[s[l]] == 0) m.erase(s[l]);
                l++;
            }
            m[s[r]]++;

            maxLen = max(maxLen, r-l+1);

            r++;
        }
        return maxLen;
    }
};