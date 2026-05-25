class Solution {
public:
    void solve(int i, vector<int>& nums, vector<vector<int>> &res, vector<int>& temp){
        if(i==nums.size()){
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i+1, nums, res, temp);
        temp.pop_back();
        solve(i+1, nums, res, temp);

        return;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(0, nums, res, temp);

        unordered_map<int, int> mpp;
        int maxi = 0;
        for(int i = 0; i < res.size(); i++){
            int orr= 0;
            for(int j =0; j < res[i].size(); j++){
                orr |= res[i][j];
            }
            mpp[orr]++;
            maxi = max(maxi, orr);
        }

        return mpp[maxi];
    }
};