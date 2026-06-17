class Solution {
public:
    long long mod = 1e9+7;
    long long splitArray(vector<int>& nums) {
        int n = nums.size();

        vector<bool> isPrime(n+1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(long long i = 2; i <= n; i++){
            for(long long j = i*i; j <= n; j+=i){
                isPrime[j] = false;
            }
        }

        vector<long long> A, B;
        for(int i = 0; i < n; i++){
            if(isPrime[i] == true){
                A.push_back(nums[i]);
            } else{
                B.push_back(nums[i]);
            }
        }

        long long sumA = accumulate(A.begin(), A.end(), 0LL);
        long long sumB = accumulate(B.begin(), B.end(), 0LL);

        return abs(sumA-sumB);
    }
};