class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        set<int> st;
        for(int x : nums){
            st.insert(x);
        }

        vector<int> result;

        for(int i =1; i <=n; i++){
            if(!st.count(i))  result.push_back(i);
        }

        return result;
    }
};