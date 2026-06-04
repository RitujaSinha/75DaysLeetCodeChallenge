class Solution {
public:
    int totalWaviness(int num1, int num2) {
        
        int wavi =0;
        for(int i = num1; i <= num2; i++){
            vector<int> t;

            int num = i;
            while(num > 0){
                int rem = num % 10;
                t.push_back(rem);
                num /= 10;
            }

            for(int i = 1; i < t.size()-1; i++){
                if((t[i] > t[i-1] && t[i] > t[i+1]) || (t[i] < t[i-1] && t[i] < t[i+1])){
                    wavi++;
                }
            }
        }
        return wavi;
    }
};