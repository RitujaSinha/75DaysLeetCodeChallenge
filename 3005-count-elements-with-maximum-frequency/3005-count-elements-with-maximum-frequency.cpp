class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(101, 0);

        for(int num: nums){
            freq[num]++;
        }

        int maxi = *max_element(freq.begin(), freq.end());

        int cnt = count(freq.begin(), freq.end(), maxi);

        return cnt*maxi;
    }
};