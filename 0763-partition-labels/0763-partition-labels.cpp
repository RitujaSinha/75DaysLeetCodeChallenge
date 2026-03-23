class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        unordered_map<int, int> mpp;
        for(int i =0; i < n; i++){
            mpp[s[i]] =i;
        }

        vector<int> res;
        int i =0;
        while(i < n){
            int maxi = i;

            for(int j =i; j <= maxi; j++){
                maxi = max(maxi, mpp[s[j]]);
            }

            res.push_back(maxi -i+1);
            i=maxi+1;
        }
        return res;
    }
};