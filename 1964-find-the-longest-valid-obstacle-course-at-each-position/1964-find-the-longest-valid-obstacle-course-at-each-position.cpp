class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();

        vector<int> result(n);


        vector<int> sorted;

        for(int i = 0; i < n; i++){

            auto it = upper_bound(sorted.begin(), sorted.end(), obstacles[i]);

            int idx = it-sorted.begin();

            if(it == sorted.end()){
                sorted.push_back(obstacles[i]);
            } else{
                *it = obstacles[i];
            }

            result[i] = idx+1;
        }
        return result;
    }
};