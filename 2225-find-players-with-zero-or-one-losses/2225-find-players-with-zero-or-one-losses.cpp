class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) { 
        int n = matches.size();

        set<int> st;
        for(int i =0; i < n; i++){
            st.insert(matches[i][0]);
            st.insert(matches[i][1]);
        }

        unordered_map<int, int> mpp;

        vector<int> winner;
        vector<int> defeat1;

        for(int i =0; i < n; i++){
            mpp[matches[i][1]]++;
        }

        for(auto it: st){
            if(mpp.find(it) == mpp.end()){
                winner.push_back(it);
            } 
        }

        for(auto &it: mpp){
            if(it.second == 1){
                defeat1.push_back(it.first);
            }
        }

        sort(defeat1.begin(), defeat1.end());
        // vector<vector<int>> result; // No need
        // result.push_back(winner);
        // result.push_back(defeat0);
        return {winner, defeat1};

    }
};