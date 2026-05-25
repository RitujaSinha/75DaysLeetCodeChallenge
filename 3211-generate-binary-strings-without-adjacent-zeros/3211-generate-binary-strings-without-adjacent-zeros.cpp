class Solution {
public:
    void solve(int len, int n, vector<string> &res, string &temp){
        if(temp.size() == n && len == 0){
            res.push_back(temp);
            return;
        }

        temp.push_back('1');
        solve(len-1, n, res, temp);
        temp.pop_back();

        temp.push_back('0');
        solve(len-1, n, res, temp);
        temp.pop_back();
    }

    bool valid(string &temp){
        int n = temp.size();

        if(n < 2) return true;

        int l=0, r=0;
        int cnt = 0;
        while(r < n){
            if(temp[r] == '1'){
                cnt++;
            }

            if(r-l+1 > 2){
                if(temp[l] == '1') cnt--;
                l++;
            }
            if(r-l+1 == 2){
                if(cnt==0) return false;
            }
            r++;
        }
        if(cnt==0) return false;
        return true;
    }

    vector<string> validStrings(int n) {
        vector<string> res;
        string temp = "";
        int len = n;
        solve(len, n, res, temp);

        vector<string> ans;
        for(int i = 0; i < res.size(); i++){
            if(valid(res[i])){
                ans.push_back(res[i]);
            }
        }
        return ans;
    }
};