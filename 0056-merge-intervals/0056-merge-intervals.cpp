class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& mergedIntervals) {
        int n = mergedIntervals.size();
        vector<vector<int>> result;

        if(mergedIntervals.size() == 0){
            return result;
        }

        sort(mergedIntervals.begin(), mergedIntervals.end());
        vector<int> tempIntervals = mergedIntervals[0];

        for(auto &it: mergedIntervals){
            if(it[0] <= tempIntervals[1]){
                tempIntervals[1] = max(it[1], tempIntervals[1]);
            } else{
                result.push_back(tempIntervals);
                tempIntervals =it;
            }
        }
        result.push_back(tempIntervals);
        return result;
    }
};