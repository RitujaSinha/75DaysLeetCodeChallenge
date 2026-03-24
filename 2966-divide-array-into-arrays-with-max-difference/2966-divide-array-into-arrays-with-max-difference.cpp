class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> temp;

        int l=0, r=0;
        while(r< n){
            if((nums[r] - nums[l]) > k) return {};

            temp.push_back(nums[r]);

            if(l==r){
                r++;
                continue;
            }

            if((r-l+1) == 3){
                result.push_back(temp);
                l=r+1;
                temp.clear();
            }
            r++;
        }
        return result;
    }
};