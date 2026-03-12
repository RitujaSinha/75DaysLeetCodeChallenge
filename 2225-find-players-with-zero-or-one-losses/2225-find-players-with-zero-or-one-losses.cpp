class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) { 
         unordered_map<int,int> loss;

        for(auto &m : matches){
            loss[m[0]] += 0;   // ensure winner exists
            loss[m[1]]++;      // count loss
        }

        vector<int> zeroLoss;
        vector<int> oneLoss;

        for(auto &it : loss){
            if(it.second == 0) zeroLoss.push_back(it.first);
            else if(it.second == 1) oneLoss.push_back(it.first);
        }

        sort(zeroLoss.begin(), zeroLoss.end());
        sort(oneLoss.begin(), oneLoss.end());

        return {zeroLoss, oneLoss};

    }
};