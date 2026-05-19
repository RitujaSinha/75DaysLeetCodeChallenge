class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();

        if(n % k != 0) return false;

        unordered_map<int, int> freq;
        for(int n: nums){
            freq[n]++;
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i <n ; i++){
            if(freq[nums[i]] == 0) continue;

            int start = nums[i];

            for(int j = 0; j < k; j++){
                int set = start + j;

                if(freq[set] == 0) return false;

                freq[set]--;
            }
        }
        return true;
    }
};