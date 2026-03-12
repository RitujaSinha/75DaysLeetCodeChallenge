class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) { 
        int n = matches.size();

        unordered_map<int, int> mpp1;
          unordered_map<int, int> mpp2;

        vector<int> zeroMatchLost;
        vector<int> oneMatchLost;

        for(int i =0; i < n; i++){
            mpp2[matches[i][1]]++;
        }

         for(int i =0; i < n; i++){
            mpp1[matches[i][0]]++;
        }

        for(auto &it: mpp1){
            if(mpp2.find(it.first) == mpp2.end()){
                zeroMatchLost.push_back(it.first);
            } 
        }

        for(auto &it: mpp2){
            if(it.second == 1){
                oneMatchLost.push_back(it.first);
            }
        }

        sort(zeroMatchLost.begin(), zeroMatchLost.end());
        sort(oneMatchLost.begin(), oneMatchLost.end());
        // vector<vector<int>> result; // No need
        // result.push_back(winner);
        // result.push_back(defeat0);
        return {zeroMatchLost, oneMatchLost};

    }
};