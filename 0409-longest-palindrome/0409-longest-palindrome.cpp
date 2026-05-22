class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();

        unordered_map<int, int> mpp;
        for(char c: s){
            mpp[c]++;
        }

        int maxL = 0;
        bool one= false;
        for(auto &it: mpp){
            if(it.second % 2 == 0) maxL += it.second;
            else{
                maxL += it.second-1;
                one = true;
            }
        }
        if(one) maxL+=1;
        return maxL;
    }
};