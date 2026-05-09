class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        
        int st = 1, end = num;

        while(st <= end){
            int mid = st + (end-st)/2;

            if(1LL * mid*mid == num){
                return true;
            } else if(1LL * mid*mid > num){
                end= mid-1;
            } else{
                st =mid+1;
            }
        }
        return false;
    }
};