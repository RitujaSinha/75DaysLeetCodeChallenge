class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        vector<int> freq(256, 0);

        int maxL = 0;
        int l = 0, r= 0;
        while(r < n){
            
            while(freq[s[r]] > 0){
                freq[s[l]]--;
                l++;
            }

            freq[s[r]]++;

            maxL = max(maxL, r-l+1);

            r++;
        }
        return maxL;
    }
};