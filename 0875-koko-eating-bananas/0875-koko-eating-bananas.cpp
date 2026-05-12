class Solution {
public:
    bool isValid(vector<int>& piles, int h, int k){
        
        long long hour = 0;
        for(int i =0; i < piles.size(); i++){
            if(piles[i] < k){
                hour++;
            } else{
                hour+= ceil((double)piles[i]/k);//koko can spend multiple hours in one pile
            }
        }
        return hour <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int st =1;
        int end = *max_element(piles.begin(), piles.end());

        int ans =0;
        while(st <= end){
            int mid = st +(end-st)/2;

            if(isValid(piles, h, mid)){
                ans = mid;
                end = mid-1;
            } else{
                st=mid+1;
            }
        }
        return ans;
    }
};