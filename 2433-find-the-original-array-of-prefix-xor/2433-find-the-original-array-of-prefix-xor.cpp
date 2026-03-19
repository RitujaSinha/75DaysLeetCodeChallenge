class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n =pref.size();

        if(n==1) return pref;

        if(n==2){
            return {pref[0], pref[0] ^ pref[1]};
        }
        vector<int> result;
        result.push_back(pref[0]);

        long long j =1;
        for(long long i = 0; i<= 1000000000 && j < n; i++){
             i = pref[j] ^ pref[j-1];
            if((pref[j-1] ^ i) == pref[j]){
                result.push_back(i);
                i=-1;
                j++;
            }
        }
        return result;
    }
};