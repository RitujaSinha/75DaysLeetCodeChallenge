class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefixS(n, 0);
        prefixS[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixS[i] = prefixS[i-1] + nums[i];
        }

        unordered_map<int, int> mpp;

        int cnt = 0;
        for(int j = 0; j < n; j++){

            if(prefixS[j] == k) cnt++;

            int val = prefixS[j] - k;

            if(mpp.find(val) != mpp.end()){
                cnt += mpp[val];
            }
            // if(mpp.find(prefixS[j]) == mpp.end()){
            //     mpp[prefixS[j]] = 0;
            // }

            mpp[prefixS[j]]++;
        }
        return cnt;
    }
};