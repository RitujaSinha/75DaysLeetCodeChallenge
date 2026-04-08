class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();

        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        vector<int> temp = nums[0];

        for(auto &it: nums){
            if(it[0] <= temp[1]){
                temp[1]= max(temp[1], it[1]);
            } else{
                result.push_back(temp);
                temp=it;
            }
        }

        result.push_back(temp);
        return result;
    }
};