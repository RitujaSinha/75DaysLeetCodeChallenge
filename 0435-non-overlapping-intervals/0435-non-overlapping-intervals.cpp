class Solution {
public:

    static bool comp(vector<int> &v1, vector<int> &v2){
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //prerequistics - N meeting in one Room (striver's Greedy playlist)
        //Inverse of N meeting in one Room


        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), comp);

        int cnt =1;
        int lastEndTime = intervals[0][1];

        for(int i =1; i < n; i++){
            if(intervals[i][0] >= lastEndTime){
                cnt++;
                lastEndTime = intervals[i][1];
            }
        }
        return n-cnt;
    }
};