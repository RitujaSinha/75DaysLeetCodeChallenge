class Solution {
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        if(a.first == b.first){
            return b.second < a.second;
        }
        return a.first < b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(int num: nums){
            mp[num]++;
        }

        vector<pair<int, int>> vec;
        for(auto it: mp){
            vec.push_back({it.second, it.first});
        }

        sort(vec.begin(), vec.end(), comp);

        vector<int> ans;
        for(int i =0; i < vec.size(); i++){
            int cnt = vec[i].first;
            while(cnt!=0){
                ans.push_back(vec[i].second);
                cnt--;
            }
        }
        return ans;
    }
};