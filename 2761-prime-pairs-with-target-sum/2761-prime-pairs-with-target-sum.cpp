class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        
        vector<bool> isPrime(n+1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(long long i =2; i <= n; i++){
            for(long long j = i*i; j <= n; j+=i){
                isPrime[j] = false;
            }
        }

        int x =1, y = n;

        vector<vector<int>> vec;
        while(x<=y){
            if(!isPrime[x]){
                x++;
                continue;
            }
            if(!isPrime[y]){
                y--;
                continue;
            }

            if(x + y < n){
                x++;
            } else if(x + y > n){
                y--;
            } else{
                vec.push_back({x, y});
                x++; y--;
            }
        }
        return vec;
    }
};