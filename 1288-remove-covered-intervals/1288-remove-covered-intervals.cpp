class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int m = intervals.size();
        int n = intervals[0].size();

        sort(intervals.begin(), intervals.end(), comp);
        int cover=0;
           for(int j = 0; j < m; j++){
            for(int i = 0; i < j; i++){
                if(intervals[j][1] <= intervals[i][1]){
                    cover++;
                    break;   // Count this interval only once
                }
            }
        }

        return m - cover;
    }
};