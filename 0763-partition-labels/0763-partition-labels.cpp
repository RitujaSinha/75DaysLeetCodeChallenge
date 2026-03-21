class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        vector<int> result;

        unordered_map<char, int> mpp;
        for(int i =0; i < n; i++){
            mpp[s[i]] = i;
        }

        for(int i =0; i < n; i++){
            unordered_map<char, int> m;
            int maxi = mpp[s[i]];
            for(int j =i+1; j <=maxi; j++){
                m[s[j]]++;
                maxi = max(maxi, mpp[s[j]]);
            }

            result.push_back(maxi - i + 1);
            i = maxi;

        }
        return result;
    }
};