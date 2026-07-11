class Solution {
public:
    int solve(int i, int j, vector<int> &nums){
        if(i > j) return 0;

        if(i == j) return nums[i];

        int first = nums[i] + min(solve(i+1, j-1, nums), solve(i+2, j, nums));
        int last = nums[j] + min(solve(i+1, j-1, nums), solve(i, j-2, nums));

        return max(first, last);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        int sm = accumulate(nums.begin(), nums.end(), 0);

        int p1 = solve(0, n-1, nums);
        int p2 = sm-p1;
        return p1 >= p2;
    }
};