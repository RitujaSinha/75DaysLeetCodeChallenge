class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_multimap<int, int> mpp;// unordered_map overrides the values that's why use unordered_multimap

        int ans =0;
        for(int i =0; i < n;i++){
            int more = k - nums[i];

            // if(mpp.find(more) != mpp.end()){
            //     ans++;
            //     mpp.erase(more);
            //     continue;
            // }

            //As multimap delete all occurences of more
            auto it = mpp.find(more);

            if(it != mpp.end()){
            ans++;
            mpp.erase(it);
            }
            else mpp.insert({nums[i] , i});
        }
        return ans;
    }
};