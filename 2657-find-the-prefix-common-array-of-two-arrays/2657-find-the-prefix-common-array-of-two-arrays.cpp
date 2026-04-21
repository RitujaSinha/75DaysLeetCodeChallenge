class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans;

        unordered_map<int, int> m;

        for(int i =0; i < n; i++){
            m[A[i]]++;
            m[B[i]]++;

            int count =0;
            for(auto &it: m){
                if(it.second == 2) count++;
            }

            ans.push_back(count);
        }
        return ans;
    }
};