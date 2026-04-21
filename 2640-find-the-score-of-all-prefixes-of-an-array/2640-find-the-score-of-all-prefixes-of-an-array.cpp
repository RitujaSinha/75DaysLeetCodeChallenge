class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> conver(n);
        vector<long long> pref(n);
        pref[0] = nums[0];

        for(int i =1; i < n; i++){
            pref[i] = max((long long)nums[i], pref[i-1]);
        }

        for(int i =0; i < n; i++){
            if(i== 0){
                conver[i] = 2LL * nums[i];
            } else{
                long long val = nums[i] + pref[i];
                conver[i] = val + conver[i-1];
            }
        }
        return conver;
    }
};