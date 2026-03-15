class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;


        long long commas =0;

        string s = to_string(n);

        if(s.size() >=4 && s.size() <= 6){
            long long number = n - 999;
            commas += (number * 1);
        } else if(s.size() > 6 && s.size() <= 9){
            commas += (999999-999)*1;
            long long number = n - 999999;

            commas += (number * 2);
        }
        else if(s.size() >9 && s.size() <= 12){
             commas += (999999-999)*1;
            commas += (999999999 - 999999) * 2;
            long long number = n - 999999999;

            commas += (number * 3);
        }
        else if(s.size() > 12 && s.size() <= 15){
              commas += (999999-999)*1;
            commas += (999999999 - 999999) * 2;
            commas+= (999999999999-999999999) * 3;
            long long number = n - 999999999999;

            commas += (number * 4);
        } else if(s.size() >= 16 && s.size() <= 18){
            commas += (999999 - 999) * 1;
            commas += (999999999 - 999999) * 2;
            commas += (999999999999 - 999999999) * 3;
            commas += (999999999999999 - 999999999999) * 4;
            long long number = n - 999999999999999;
            commas += number * 5;
        }


        
        return commas;
    }
};