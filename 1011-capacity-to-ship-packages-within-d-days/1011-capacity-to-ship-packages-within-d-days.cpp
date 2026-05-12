class Solution {
public:
    bool isValid(vector<int>& weights, int days, int minWeightAllow){
        int n = weights.size();

        int day=1;
        int packages  =0;

        for(int i =0; i < n; i++){
            if(packages+weights[i] <= minWeightAllow){
                packages +=weights[i];
            } else{
                day++;
                packages= weights[i];
            }
        }
        return day <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int st = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);

        int ans =0;
        while(st <= end){
            int mid = st +(end-st)/2;

            if(isValid(weights, days, mid)){
                ans= mid;
                end = mid-1;
            } else{
                st=mid+1;
            }
        }
        return ans;
    }
};