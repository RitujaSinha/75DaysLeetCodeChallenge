class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string res1= "";
        for(int i = 0; i < s.size(); i++){
            if(!res1.empty() && s[i] == '#'){
                res1.pop_back();
            } else if(s[i] != '#'){
                res1 +=s[i];
            }
        }

        cout << res1 << endl;

         string res2 =  "";
        for(int i = 0; i < t.size(); i++){
            if(!res2.empty() && t[i] == '#'){
                res2.pop_back();
            } else if(t[i] != '#'){
                res2 +=t[i];
            }
        }

        cout << res2 << endl;

        return res1==res2;
    }
};