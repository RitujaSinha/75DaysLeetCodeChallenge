class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();

        long long m = mass;

        sort(asteroids.begin(), asteroids.end());

        for(int i =0; i < n; i++){
            if(m < asteroids[i]){
                return false;
            }
            m+=asteroids[i];
        }
        return true;
    }
};