class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();

        unordered_map<int, int> mpp;
        
        int count = 0;
        for(auto x: time){
            int t = x % 60;
            int y = (60-t)%60;
            count += mpp[y];
            mpp[t]++;
        }
        return count;
    }
};