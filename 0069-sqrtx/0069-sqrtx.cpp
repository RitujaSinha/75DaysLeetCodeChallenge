class Solution {
public:
    int mySqrt(int x) {
        
        int st = 0, end = x;
        int ans  =0;

        while(st <= end){
            int mid = st +(end-st)/2;

            if(pow(mid, 2) <= x){
                ans = mid;
                st = mid+1;
            } else{
                end = mid-1;
            }
        }
        return ans;
    }
};