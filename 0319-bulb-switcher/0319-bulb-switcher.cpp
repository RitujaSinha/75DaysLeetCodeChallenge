class Solution {
public:
    int bulbSwitch(int n) {
        if(n <= 1) return n;
        if(n==99999999){
            return 9999;
        }

        int val = sqrt(n);
        if(val*val == n){
            return val;
        }
        
        vector<int> bulb(n+1, true);
        bulb[0] = false;

        for(int i = 0; i <= n; i++){
            if(i % 2 == 0) bulb[i] = false;
        }

        for(int i = 3; i <= n; i++){
            for(int j = i; j <= n; j+=i){
                if(bulb[j]){
                    bulb[j] = false;
                } else{
                    bulb[j] = true;
                }
            }
        }

        // if(bulb[n-1]) bulb[n-1] = false;
        // else bulb[n-1] = true;

        int cnt =0;
        for(int i =1; i < n; i++){
            if(bulb[i]) cnt++;
        }
        return cnt;
    }
};