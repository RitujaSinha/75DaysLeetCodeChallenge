class Solution {
public:
    string resultingString(string s) {
        int n = s.size();

        stack<char> st;

        for(int i = 0; i < n; i++){
            if(!st.empty() && ((s[i]-1 == st.top()) ||
            (s[i]+1 == st.top()) || (st.top()-1 == s[i]) || (st.top()+1==s[i]) || (st.top() == 'a' && s[i] == 'z') || (st.top() == 'z' && s[i] == 'a'))){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }

        string res = "";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};