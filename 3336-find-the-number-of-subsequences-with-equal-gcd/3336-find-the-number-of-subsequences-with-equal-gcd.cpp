class Solution {
public:
    int t[201][201][201];
    int mod = 1e9+7;
    int solve(int i, int gcd1, int gcd2, vector<int>& nums){
        if(i == nums.size()){
            if(gcd1 == 0 || gcd2 == 0) return 0;
            return gcd1 == gcd2;
        }

        if(t[i][gcd1][gcd2] != -1) return t[i][gcd1][gcd2];

        long long seq1 = solve(i+1, gcd(nums[i], gcd1) , gcd2, nums);
        long long seq2 = solve(i+1, gcd1, gcd(nums[i], gcd2), nums);

        long long notTake = solve(i+1, gcd1, gcd2, nums);

        return t[i][gcd1][gcd2] = (seq1 + seq2 + notTake) % mod; 
    }
    int subsequencePairCount(vector<int>& nums) {
        
        memset(t, -1, sizeof(t));
        return solve(0,0, 0, nums);
    }
};