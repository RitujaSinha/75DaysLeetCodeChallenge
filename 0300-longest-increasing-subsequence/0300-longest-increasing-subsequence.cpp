class Solution {
public:
    int solve(int i, int P, vector<int>& nums, vector<vector<int>> &t){
        if(i == nums.size()){
            return 0;
        }

        if(t[i][P+1] != -1) return t[i][P+1];

        int take =0;
        if(P == -1 || nums[P] < nums[i]){
            take = 1 + solve(i+1, i, nums, t);
        }
        int notTake = solve(i+1, P, nums, t);

        return t[i][P+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> t(n, vector<int> (n+1, -1));
        return solve(0, -1, nums, t);
    }
};