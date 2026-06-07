class Solution {
public:
    void solve(int i, string &pattern, vector<string> &validString, string &temp, vector<int> &used){
        if(i==pattern.size()){
            if(pattern.size()+1 == temp.size()){
                validString.push_back(temp);
            }
            return;
        }

        for(int num = '1'; num <= '9'; num++){
            if(used[num-'0']) continue;
            
            if(temp.empty()){
                temp.push_back(num);
                used[num-'0'] = 1;

                solve(i, pattern, validString, temp, used);
                temp.pop_back();
                used[num-'0'] = 0;
            }
            else {
                if(pattern[i] == 'I' && num > temp.back()){
                    temp.push_back(num);
                    used[num-'0'] = 1;

                    solve(i+1, pattern, validString, temp, used);
                    temp.pop_back();
                    used[num-'0'] = 0;
                } else if(pattern[i] == 'D' && num < temp.back()){
                    temp.push_back(num);
                    used[num-'0'] = 1;

                    solve(i+1, pattern, validString, temp, used);
                    temp.pop_back();
                    used[num-'0'] = 0;
                }
            }
        }
    }
    string smallestNumber(string pattern) {
        
        vector<string> validString;
        string temp ="";
        vector<int> used(10, 0);
        solve(0, pattern, validString, temp, used);

        
        sort(validString.begin(), validString.end());
        return validString[0];
    }
};