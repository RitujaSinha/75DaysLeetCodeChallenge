class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> C(n);

        unordered_map<int, int> m;
        for(int i = 0; i < n; i++){

            m[A[i]]++;
            m[B[i]]++;

            int cnt = 0;
            for(auto &it: m){
                if(it.second==2){
                    cnt++;
                }
            }

            C[i] = cnt;
        }
        return C;
    }
};