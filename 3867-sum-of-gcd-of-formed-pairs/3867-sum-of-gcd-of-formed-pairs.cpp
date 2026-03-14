class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixMax(n);

        prefixMax[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixMax[i] = max(prefixMax[i-1], nums[i]);
        }

        vector<int> prefixGcd(n);

        // int k =0;

        // while(k< n){
        // int gcd =1;
        // int a = nums[k];
        // int b = prefixMax[k];
        // for(int i =1; i <= min(a,b); i++){
        //     if((a % i == 0) && (b % i ==0)) gcd = i;
        // }
        //     prefixGcd[k] = gcd;
        //     k++;
        // }

        for(int k =0; k < n; k++){
            prefixGcd[k]= __gcd(nums[k], prefixMax[k]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum =0;

        int i =0, j =n-1;
        while(i < j){
            int a = prefixGcd[i];
            int b = prefixGcd[j];
            // for(int l =1; l <= min(a, b); l++){
            //     if((a % l == 0) && (b % l ==0)) gcd1 = l;
            // }
            sum += __gcd(a, b);

            i++;
            j--;
        }
        return sum;
    }
};