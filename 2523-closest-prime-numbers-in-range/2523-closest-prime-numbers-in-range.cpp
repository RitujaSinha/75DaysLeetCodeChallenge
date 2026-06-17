class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        
        vector<bool> isPrime(right+1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(long long i = 2; i <= right; i++){
            for(long long j = i*i; j <= right; j+=i){
                isPrime[j] = false;
            }
        }

        int num1 =-1, num2 =-1;
        
        int mini = INT_MAX;
        for(int i = left; i <= right; i++){
            for(int j  = i+1; j<=right; j++){
                if(isPrime[i] && isPrime[j]){
        
                    if(mini > j-i){
                        mini = j-i;
                        num1 = i;
                        num2 = j;
                    }

                    if(mini <= 2) return {num1, num2};
                }
            }
        }
        return {num1, num2};
    }
};