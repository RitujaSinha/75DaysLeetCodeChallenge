class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return false;


        sort(nums.begin(), nums.end());

        int maxi = *max_element(nums.begin(), nums.end());
        if(maxi >= n) return false;

        if(nums[n-1] != nums[n-2]) return false;

        unordered_map<int, int> m;
        for(int num: nums){
            m[num]++;
        }

        int cnt = 0;
        int cnt2= 0;
        for(auto it: m){
            if(it.second == 2){
                cnt++;
            } else if(it.second > 2){
                cnt2++;
            }
        }

        if(cnt2) return false;
        return cnt==1;
    }
};