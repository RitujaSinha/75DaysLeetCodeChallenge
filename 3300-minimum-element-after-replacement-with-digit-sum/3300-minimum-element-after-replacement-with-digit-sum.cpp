class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();

        int ans =INT_MAX;
        for(int i = 0; i < n; i++){

            int num = nums[i];
            int sm = 0;
            while(num > 0){
                int rem = num % 10;
                sm += rem;
                num/=10;
            }
            ans = min(sm, ans);
        }
        return ans;
    }
};