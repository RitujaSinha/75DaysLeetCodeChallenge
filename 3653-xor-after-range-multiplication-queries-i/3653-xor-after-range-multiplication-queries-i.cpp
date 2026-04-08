class Solution {
public:
    int MOD = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        for(int i =0; i < queries.size(); i++){
            int idx = queries[i][0];

            while(idx <= queries[i][1]){
                nums[idx] = ((long long)nums[idx] * queries[i][3]) % MOD;

                idx+= queries[i][2];
            }
        }

        int res =0;
        for(int &num: nums){
            res ^= num;
        }
        return res;
    }
};