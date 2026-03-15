class Solution {
public:
    bool isSameAfterReversals(int num) {
        int temp  = num;

        long long rev=0;
        while(temp > 0){
            rev = rev * 10 + temp% 10;
            temp/=10;
        }

         long long result=0;
        while(rev > 0){
            result = result * 10 + rev% 10;
            rev/=10;
        }

        if(result == num) return true;
        return false;
    }
};