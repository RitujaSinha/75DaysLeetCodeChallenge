class Solution {
public:
     int solve(vector<int>& start1, vector<int>& dur1, vector<int>& start2, vector<int>& dur2) {
        int n = start1.size();
        int m = start2.size();

        vector<int> firstEnd;
        for(int i = 0; i < n; i++){
            firstEnd.push_back(start1[i] + dur1[i]);
        }

        sort(firstEnd.begin(), firstEnd.end());

        vector<pair<int,int>> second;
        for(int i = 0; i < m; i++){
            second.push_back({start2[i], dur2[i]});
        }

        sort(second.begin(), second.end());

        vector<int> suffix(m);
        for(int i = 0; i < m; i++){
            suffix[i] = second[i].first + second[i].second;
        }

        for(int i = m - 2; i >= 0; i--){
            suffix[i] = min(suffix[i], suffix[i + 1]);
        }

        int ans = INT_MAX;
        int minDur = INT_MAX;
        int j = 0;

        for(int i = 0; i < n; i++){
            int endFirst = firstEnd[i];

            while(j < m && second[j].first <= endFirst){
                minDur = min(minDur, second[j].second);
                j++;
            }

            // second ride already open
            if(minDur != INT_MAX){
                ans = min(ans, endFirst + minDur);
            }

            // second ride starts later
            if(j < m){
                ans = min(ans, suffix[j]);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int time1 = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int time2 = solve(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(time1, time2);
    }
};