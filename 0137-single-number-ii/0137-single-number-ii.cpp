class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        int result = 0;
        for(int k = 0; k <= 31; k++){
            int temp = 1 << k;

            int countOnes = 0, countZeros = 0;
            for(int num: nums){
                if((num & temp) == 0){
                    countZeros++;
                } else{
                    countOnes++;
                }
            }

            if(countOnes % 3 == 1){
                result |= (1 << k);
            }
        }
        return result;
    }
};