class Solution {
public:
    static bool comp(vector<int> &v1, vector<int> &v2){
        return v1[1] > v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int n= boxTypes.size();

        sort(boxTypes.begin(), boxTypes.end(), comp);

        int units= 0;
        for(int i =0; i < n ; i++){
            if(boxTypes[i][0] <= truckSize){
                units+= (boxTypes[i][0] * boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
            } else{
                units += (truckSize * boxTypes[i][1]);
                break;
            }
        }
        return units;
    }
};