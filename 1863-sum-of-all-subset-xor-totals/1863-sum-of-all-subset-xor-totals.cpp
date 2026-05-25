class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>> &res){
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i+1, nums, temp, res);
        temp.pop_back();
        solve(i+1, nums, temp, res);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(0, nums, temp, res);

        int sum = 0;
        for(int i = 0; i < res.size(); i++){
            int xorr= 0;
            for(int j = 0; j < res[i].size(); j++){
                xorr ^= res[i][j];
            }
            sum += xorr;
        }
        return sum;
    }
};