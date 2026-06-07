class Solution {
public:
    int countPrimes(int n) {
        
        vector<bool> isPrime(n+1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i * i < n; i++){
            for(int j = i*i; j <= n; j+=i){
                isPrime[j] = false;
            }
        }

        int count= 0;
        for(int i = 0; i < isPrime.size()-1; i++){
            if(isPrime[i]) count++;
        }
        return count;
    }
};