class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;

        string s = to_string(n);

        long long commas =0;
        if(s.size() >= 4 && s.size() <= 6){
            commas += (n-999) * 1;
        } else if(s.size() >= 7 && s.size() <= 9){
            commas += 1 * (999999-999);
            commas += 2 * (n-999999);
        } else if(s.size() >= 10 && s.size() <= 12){
            commas += 1 * (999999-999);
            commas += 2 * (999999999-999999);
            commas += 3 * (n-999999999);
        } else if(s.size() >= 13 && s.size() <= 15){
            commas += 1 * (999999-999);
            commas += 2 * (999999999-999999);
            commas += 3 * (999999999999-999999999);
            commas += 4 * (n-999999999999);
        } else if(s.size() >= 15 && s.size() <= 18){
            commas += 1 * (999999-999);
            commas += 2 * (999999999-999999);
            commas += 3 * (999999999999-999999999);
            commas += 4 * (999999999999999-999999999999);
            commas += 5 * (n-999999999999999);
        }
        return commas;
    }
};