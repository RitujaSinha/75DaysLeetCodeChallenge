class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> m;

        for(int &n: nums){
            m[n]++;
        }

        int sum = 0;
        for(auto it: m){
            if(it.second == 1){
                sum += it.first;
            }
        }
        return sum;
    }
};