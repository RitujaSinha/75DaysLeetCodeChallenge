class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(101, 0);

        for(int &n: nums){
            freq[n]++;
        }

        int sum = 0;
        for(int i = 1; i <= 100; i++){
            if(freq[i] == 1){
                sum+=i;
            }
        }
        return sum;
    }
};