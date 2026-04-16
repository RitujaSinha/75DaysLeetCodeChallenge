class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int maxLen = 0;

        for(int i =0; i < n; i++){
            vector<int> hash(256, 0);

            for(int j = i; j <n; j++){
                if(hash[s[j]] > 0) break;

                hash[s[j]]++;

                maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen;
    }
};