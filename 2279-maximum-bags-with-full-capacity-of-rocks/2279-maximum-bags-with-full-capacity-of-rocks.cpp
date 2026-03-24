class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();

        vector<int> remainingCapacity;
        int maxFull=0;
        for(int i = 0; i < n; i++){
            int rem = capacity[i] - rocks[i];
            if(rem == 0){
                maxFull++;         
            } else{
                remainingCapacity.push_back(rem);
            }
        }

        sort(remainingCapacity.begin(), remainingCapacity.end());

        //int maxFull =0;
        for(int i =0; i < remainingCapacity.size(); i++){
            if(remainingCapacity[i] <= additionalRocks){
                additionalRocks -= remainingCapacity[i];
                maxFull++;
            } else{
                break;
            }
        }
        return maxFull;
    }
};