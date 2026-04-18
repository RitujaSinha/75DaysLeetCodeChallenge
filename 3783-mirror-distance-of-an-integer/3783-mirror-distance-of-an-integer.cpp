class Solution {
public:
    int mirrorDistance(int n) {
        
        int temp=n;
        int result=0;
        while(temp>0){
            int rem = temp%10;
            result=result*10+rem;
            temp/=10;
        }

        return abs(n-result);
    }
};