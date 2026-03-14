class Solution {
public:
    void solve(int idx,int cnt, vector<string> &s, int n, int k, vector<string> &result, string temp){
        if(cnt == n){
            result.push_back(temp);
            return;
        }

        for(int i =0; i < s.size(); i++){
            // if(i > 0 && s[i] == s[i-1]) continue;
            if(!temp.empty() && temp.back() == s[i][0]) continue;

            temp+=s[i];

            solve(0,cnt+1, s, n, k, result, temp);

            temp.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        vector<string> s= {"a", "b", "c"};

        vector<string> result;
        string temp="";

        solve(0,0, s, n, k, result, temp);


        sort(result.begin(), result.end());

        int count =0;
        for(int i =0; i< result.size();i++){
            count++;

            if(count== k){
                return result[i];
            }
        }

        cout << count;

        if(count < k){
            return "";
        }

        return "";
    }
};