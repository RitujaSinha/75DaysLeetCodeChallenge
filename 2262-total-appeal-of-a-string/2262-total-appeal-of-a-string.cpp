class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();

        unordered_map<char, long long> mpp;
        
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(mpp.find(s[i]) != mpp.end()){
                ans += (i - mpp[s[i]])*(n-i);

                // mpp[s[i]] = i;
            } else{
                ans += (i+1)*(n-i);
            }

            mpp[s[i]] = i;
        }
        return ans;
    }
};