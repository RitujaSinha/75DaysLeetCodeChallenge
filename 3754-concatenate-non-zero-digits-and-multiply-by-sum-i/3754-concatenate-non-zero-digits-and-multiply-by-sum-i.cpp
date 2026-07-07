class Solution {
public:
    long long sumAndMultiply(int n) {
        
        int res= 0;
        int temp = n;
        int sm =0;
        while(temp > 0){
            int rem  = temp %10;
            if(rem != 0) res = res * 10 + rem;
            sm+=rem;
            temp/=10;
        }

        temp = res;
        long long ans = 0;
        while(temp > 0){
            int rem  = temp %10;
            ans = ans * 10 + rem;
            temp/=10;
        }
        return ans * sm;
    }
};