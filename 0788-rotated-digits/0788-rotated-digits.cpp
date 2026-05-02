class Solution {
public:
    int isValid(int n){
        if(n == 0) return 0;
        else if(n == 1) return 1;
        else if(n == 2) return 5;
        else if(n == 5) return 2;
        else if(n == 6) return 9;
        else if(n == 8) return 8;
        else if(n == 9) return 6;

        return -1;
    }
    int rotatedDigits(int n) {

        int count = 0;
        for(int i = 1; i <= n; i++){
            int num  =i;
            bool valid = true;
            
            int result = 0;
            int place  = 1;
            while(num > 0){
                int rem = num % 10;
                if(isValid(rem) == -1){
                    valid = false;
                    break;
                }
                result = result + isValid(rem) * place;
                place *= 10;
                num /= 10;
            }

            if(valid && result != i) count++;
        }
        return count;
    }
};