class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        long long xorr = 0;
        for(int n: nums){
            xorr ^= n;
        }

        long long rightMostSet = (xorr & (xorr-1)) ^ xorr;
        
        int b1 = 0, b2= 0;
        for(int num: nums){
            if(num & rightMostSet){
                b1 ^= num;
            } else{
                b2 ^= num;
            }
        }
        return {b1, b2};
    }
};