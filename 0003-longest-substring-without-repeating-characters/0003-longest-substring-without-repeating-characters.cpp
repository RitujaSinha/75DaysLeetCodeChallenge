class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int maxL = 0;
        for(int i = 0; i < n; i++){
            vector<int> hash(256, 0);

            for(int j = i; j < n; j++){
                if(hash[s[j]] > 0){
                    break;
                }
                hash[s[j]]++;
                maxL = max(maxL, j-i+1);
            }
        }
        return maxL;
    }
};