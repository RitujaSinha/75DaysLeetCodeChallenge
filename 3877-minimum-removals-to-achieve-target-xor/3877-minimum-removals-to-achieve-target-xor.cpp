class Solution {
public:
    int best =-1;
    map<pair<int, int>, int> mp;

    int solve(int idx, int currXor,vector<int>& nums, int target){
        if(idx >= nums.size()){
            if(currXor == target){
                return 0;
            } else{
                return INT_MAX;
            }
        }

        if(mp.find({idx, currXor}) != mp.end()){
            return mp[{idx, currXor}];
        }
        
        int take = solve(idx+1, currXor ^ nums[idx], nums, target);

        int notTake = solve(idx+1, currXor, nums, target);
        if(notTake != INT_MAX){
            notTake +=1;
        }

        return mp[{idx, currXor}] = min(notTake, take);
    }
    int minRemovals(vector<int>& nums, int target) {
        int n =nums.size();
        mp.clear();// baar baar funtion call hoga to purana values reh jayega        
        
        int ans = solve(0, 0, nums, target);
        return ans == INT_MAX ? -1 : ans;
    }
};