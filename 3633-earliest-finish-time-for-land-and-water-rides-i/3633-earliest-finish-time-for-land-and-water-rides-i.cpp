class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int time1 = INT_MAX;
        int time2 = INT_MAX;

        for(int i = 0; i < n; i++){
            int t = landStartTime[i];
            int et = landDuration[i];

            int endLand = t + et;

            for(int j = 0; j < m; j++){
                if(endLand >= waterStartTime[j]){
                    time1 = min(time1, endLand + waterDuration[j]);
                } else{
                    time1 = min(time1, waterDuration[j] + waterStartTime[j]);
                }
            }
        }

       for(int i = 0; i < m; i++){
            int t = waterStartTime[i];
            int et = waterDuration[i];

            int endWater = t + et;

            for(int j = 0; j < n; j++){
                if(endWater >= landStartTime[j]){
                    time2 = min(time2, endWater + landDuration[j]);
                } else{
                    time2 = min(time2, landDuration[j] + landStartTime[j]);
                }
            }
        }

        return min(time1 ,time2);
    }
};