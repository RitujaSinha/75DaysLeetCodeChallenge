class Solution {
public:
    int bs(vector<int>& potions, long long success, int check){
        int n = potions.size();

        int st = 0, end= n-1;

        int ans = 0;
        while(st <= end){
            int mid = st + (end-st)/2;

            if(((long long)potions[mid] * check) >= success){
                ans = n-mid;
                end = mid-1;
            } else{
                st = mid+1;
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(), potions.end());

        vector<int> ans;
        for(int i = 0; i < spells.size(); i++){
            ans.push_back(bs(potions,success, spells[i]));
        }
        return ans;
    }
};