class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> pref(n), suff(n);

        pref[0] = nums[0];
        for(int i = 1; i < n; i++){
            pref[i] = max(pref[i-1], nums[i]);
        }

        suff[n-1] = nums[n-1];
        for(int i = n-2; i>= 0; i--){
            suff[i] = min(suff[i+1], nums[i]);
        }

        vector<int> ans(n);
        ans[n-1] = pref[n-1]; //wo last element hai.. usse chota koi element nahi hai aage jisse jump kr sake
        for(int i = n-2; i>=0; i--){
            ans[i] = pref[i];

            if(pref[i] > suff[i+1]){
                ans[i] = ans[i+1];
            }
        }
        return ans;
    }
};