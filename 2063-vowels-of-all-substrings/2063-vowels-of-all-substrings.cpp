class Solution {
public:
    long long countVowels(string word) {
        int n = word.size();

        unordered_map<char, long long> mpp;
        mpp['a'] =1;
        mpp['e'] =1;
        mpp['i'] =1;
        mpp['o'] =1;
        mpp['u'] =1;

        long long ans = 0;
        for(long long i = 0; i < n; i++){
            if(mpp.find(word[i]) != mpp.end()){
                ans += ((i+1)*(n-i));
            }
        }
        return ans;
    }
};