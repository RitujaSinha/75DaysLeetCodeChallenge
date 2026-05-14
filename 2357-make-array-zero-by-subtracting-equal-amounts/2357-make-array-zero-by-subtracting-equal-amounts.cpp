class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if(n==1 && nums[0] == 0) return 0;
        if(n==1 && nums[0] != 0) return 1; 

        sort(nums.begin(), nums.end());

        unordered_map<int, int> m;
        for(int num: nums){
            m[num]++;
        }

        if(m.size() == 1 && nums[0] == 0) return 0;


        int op = 0;
        while(1){
            int mini = INT_MAX;
            for(int i = 0; i < n; i++){
                if(mini > nums[i] && nums[i] > 0){
                    mini = nums[i];
                }
            }
            int maxi = *max_element(nums.begin(), nums.end());

             op++;
            if(mini == maxi) break;

            for(int i = 0; i < n; i++){
                if(nums[i] > 0){
                    nums[i] -= mini;
                }
            }
            // op++;
        }
        return op;
    }
};