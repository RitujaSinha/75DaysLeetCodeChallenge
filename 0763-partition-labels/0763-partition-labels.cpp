class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        vector<int> lastOcc(26);

        for(int i =0; i < n; i++){
            lastOcc[s[i]-'a'] = i;
        }

        vector<int> res;
        int i =0;
        while(i < n){
            int maxi = i;

            for(int j =i; j <= maxi; j++){
                maxi = max(maxi, lastOcc[s[j]- 'a']);
            }

            res.push_back(maxi -i+1);
            i=maxi+1;
        }
        return res;
    }
};