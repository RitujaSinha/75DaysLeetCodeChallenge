class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(), pairs.end());

        vector<int> t(n, 1);

        int maxChain =1;
        for(int i =0; i < n; i++){
            for(int j =0; j < i; j++){
                if(pairs[j][1] < pairs[i][0]){
                    t[i] = max(t[j]+1, t[i]);
                    maxChain = max(maxChain, t[i]);
                }
            }
        }
        return maxChain;
    }
};