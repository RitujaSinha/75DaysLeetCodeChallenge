class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n =nums.size();
        vector<vector<int>> ans;

        if(n==0) return ans;

        sort(nums.begin(), nums.end());

        vector<int> temp = nums[0];

        for(auto &it: nums){
            if(it[0] <= temp[1]){
                temp[1] = max(it[1], temp[1]);
            } else{
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};