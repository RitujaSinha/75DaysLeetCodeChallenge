class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
       vector<vector<int>> result;
       if(n== 0) return result;

       sort(intervals.begin(), intervals.end());

       vector<bool> merge(n, false);

       for(int i =0; i < n; i++){
        if(merge[i]) continue;

        int start = intervals[i][0];
        int end = intervals[i][1];

        for(int j = i+1; j < n; j++){
            if(merge[j]) continue;

            if(end >= intervals[j][0]){
                end = max(end, intervals[j][1]);
                merge[j]= true;
            }
        }
        result.push_back({start, end});
       } 
        return result;
    }
};