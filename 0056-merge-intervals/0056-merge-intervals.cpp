class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<bool> merge(n, false);
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end());

        for(int i =0; i < n; i++){
            if(merge[i]) continue;

            int start = intervals[i][0];
            int end = intervals[i][1];

            for(int j =i+1; j < n; j++){
                if(merge[j]) continue;

                if(intervals[j][0] <= end){
                    end = max(end, intervals[j][1]);
                    merge[j] = true;
                } else{
                    break;
                }
            }
            result.push_back({start, end});
        }
        return result;
    }
};