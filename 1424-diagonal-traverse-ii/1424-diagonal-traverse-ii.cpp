class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        // int n = nums[0].size();

        unordered_map<int, vector<int>> mp;

        set<int> st;

        for(int i = 0; i < m; i++){
            int colSize = nums[i].size();
            for(int j = 0; j < colSize; j++){
                // cout << "hello" << endl;
                mp[i+j].push_back(nums[i][j]);
                st.insert(i+j);
            }
        }

        vector<int> result;
        for(int i = 0; i < st.size(); i++){

            reverse(mp[i].begin(), mp[i].end());

            for(int &num: mp[i]){
                result.push_back(num);
            }
        }
        // reverse(result.begin(), result.end());
        return result;
    }
};