class Solution {
public:
    void solve(int idx, string &pattern, vector<string> &res, string &temp, vector<int> &used){
        if(idx == pattern.size()){
            if(temp.size() == pattern.size()+1) res.push_back(temp);
            return;
        }

        for(char ch = '1'; ch <= '9'; ch++){
            if(used[ch-'0']) continue;

            if(temp.empty()){
                temp.push_back(ch);
                used[ch-'0'] = 1;

                solve(idx, pattern, res, temp,used);

                temp.pop_back();
                used[ch-'0'] = 0;
            } else{
                if(pattern[idx] == 'I'){
                    if(temp.back() < ch){
                        temp.push_back(ch);
                        used[ch-'0'] = 1;

                        solve(idx+1,pattern, res, temp,used);

                        temp.pop_back();
                        used[ch-'0'] = 0;
                    }
                } else{
                    if(temp.back() > ch){
                        temp.push_back(ch);
                        used[ch-'0'] = 1;

                        solve(idx+1,pattern, res, temp,used);

                        temp.pop_back();
                        used[ch-'0'] = 0;
                    }
                }
            }
        }
    }
    string smallestNumber(string pattern) {
        
        vector<string> res;
        string temp = "";

        vector<int> used(10, 0); 
        solve(0, pattern, res, temp, used);

        sort(res.begin(), res.end());
        return res[0];
    }
};