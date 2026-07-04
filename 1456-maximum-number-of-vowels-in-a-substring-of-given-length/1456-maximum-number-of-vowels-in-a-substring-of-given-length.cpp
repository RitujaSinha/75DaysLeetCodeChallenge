class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();

        unordered_map<char, int> mpp;
        mpp['a'] = 1;
        mpp['e'] = 1;
        mpp['i'] = 1;
        mpp['o'] = 1;
        mpp['u'] = 1;

        int l = 0, r= 0;
        int cnt =0;

        int ans = 0;
        while(r < n){

            if(mpp.find(s[r]) != mpp.end()){
                cnt++;
            }

            if(r-l+1 > k){
                if(mpp.find(s[l]) != mpp.end()){
                    cnt--;
                }
                l++;
            }

            if(r-l+1 == k){
                ans = max(ans, cnt);
            }
            r++;
        }
        return ans;
    }
};