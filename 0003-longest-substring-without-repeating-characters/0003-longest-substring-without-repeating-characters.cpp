class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int l=0, r=0;
        vector<int> hash(256, 0);
        int maxLen = 0;

        while(r < n){
            while(hash[s[r]] ==1){
                hash[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            hash[s[r]]=1;
            r++;
        }
        return maxLen;
    }
};