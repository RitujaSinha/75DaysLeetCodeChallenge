class Solution {
public:
    bool isValid(vector<int>& piles, int h, int minHours){
        int n = piles.size();
        long long hrs = 0;

        for(int i = 0; i < n; i++){
            hrs += ceil(piles[i]/(double)minHours);
        }

        return hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int st = 1;
        int end = *max_element(piles.begin(), piles.end());

        int ans = 0;
        while(st <= end){
            int mid = st + (end-st)/2;

            if(isValid(piles, h, mid)){
                ans= mid;
                end = mid-1;
            } else{
                st = mid+1;
            }
        }
        return ans;
    }
};