class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int n =nums.size();

        unordered_map<int, int> mpp;
        for(int x: nums){
            mpp[x]++;
        }

        int xorr =0;
        for(auto [k,v]: mpp){
            if(v == 2){ 
                xorr ^= k;
            }
        }
        return xorr;
    }
};