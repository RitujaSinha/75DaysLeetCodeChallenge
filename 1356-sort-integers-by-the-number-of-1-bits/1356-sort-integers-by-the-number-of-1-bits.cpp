class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();

        vector<pair<int, int>> vec;
        for(int &num: arr){
            vec.push_back({__builtin_popcount(num), num});
        }

        sort(vec.begin(), vec.end());

        vector<int> ans;
        for(int i = 0; i < vec.size(); i++){
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};