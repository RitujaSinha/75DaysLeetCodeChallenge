class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();

        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());

        vector<int> arr(maxi+1, 0);

        for(int i = 0; i < n; i++){
            arr[nums[i]]++;
        }

        for(int i = mini; i <= maxi; i++){
            if(arr[i] > 0){
                for(int j = 2*i; j <= maxi; j+=i){
                    if(arr[j] > 0){
                        arr[i] += arr[j];
                        arr[j] = 0;
                    }
                }
            }
        }

        long long sum = 0;
        for(int i = 0; i <= maxi; i++){
            if(arr[i] > 0){
                sum += 1LL * i*arr[i];
            }
        }
        return sum;
    }
};