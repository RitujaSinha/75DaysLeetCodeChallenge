class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();

        int maxi = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime(maxi+1, true);
        if(maxi >= 0) isPrime[0] = false;
        if(maxi >= 1 ) isPrime[1] = false;

        for(int i = 2; i <= maxi; i++){
            if(isPrime[i]){
                for(int j = i*i; j <= maxi; j+=i){
                    isPrime[j] =false;
                }
            }
        }

        int i = 0, j = n-1;
        while(i <= j){
            if(!isPrime[nums[i]]){
                i++;
                continue;
            } 
            if(!isPrime[nums[j]]){
                j--;
                continue;
            }
            return j-i;
        }
        return 0;
    }
};