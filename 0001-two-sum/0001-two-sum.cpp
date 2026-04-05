class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n =nums.size();

        unordered_map<int, int> m;

        for(int i =0; i < n; i++){
            int more = target-nums[i];

            if(m.find(more) != m.end()){
                return {i, m[more]};
            }

            m[nums[i]] = i;
        }
        return {};
    }
};