class Solution {
public:
    void solve(int i, vector<int>& nums, vector<vector<int>> &totalSubset, vector<int> &subset){
        if(i== nums.size()){
            totalSubset.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        solve(i+1, nums, totalSubset, subset);
        subset.pop_back();
        solve(i+1, nums, totalSubset, subset);

        return;
    }

    bool isBeautiful(vector<int> &arr, int k){
        if(arr.size() == 0) return false;
        
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr.size(); j++){
                if(i == j) continue;

                if(abs(arr[i]-arr[j]) == k) return false;
            }
        }
        return true;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> totalSubset;
        vector<int> subset;
        solve(0, nums, totalSubset, subset);

        int count =0;
        for(int i = 0; i < totalSubset.size(); i++){
            if(isBeautiful(totalSubset[i], k)) count++;
        }
        return count;
    }
};