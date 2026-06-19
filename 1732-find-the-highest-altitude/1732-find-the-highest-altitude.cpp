class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        int maxi = 0;
        int alti = 0;
        for(int i = 0; i < n; i++){
            alti += gain[i];

            maxi=max(maxi, alti);
        }
        return maxi;
    }
};