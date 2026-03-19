class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n =pref.size();

        if(n==1) return pref;

        if(n==2){
            return {pref[0], pref[0] ^ pref[1]};
        }
        vector<int> result(n);
        result[0] = pref[0];

        // long long j =1;
        for(int i = 1; i < n; i++){
             result[i] = pref[i-1] ^ pref[i];
        }
        return result;
    }
};