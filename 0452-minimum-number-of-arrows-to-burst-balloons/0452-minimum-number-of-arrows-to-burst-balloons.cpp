class Solution {
public:
    static bool comp(vector<int> &v1, vector<int> &v2){
        return v1[1] < v2[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> tempPoint(2);
        vector<vector<int>> result;

        sort(points.begin(), points.end(), comp);
        tempPoint[0] = points[0][0];
        tempPoint[1] = points[0][1];

        for(int i=1; i < n; i++){
            if(points[i][0] <= tempPoint[1]){
                tempPoint[1] = min(points[i][1], tempPoint[1]);
            } else{
                result.push_back(tempPoint);
                tempPoint = points[i];
            }
        }
        result.push_back(tempPoint);
        return result.size();
    }
};