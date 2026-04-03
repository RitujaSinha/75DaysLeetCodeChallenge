class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        stack<int> st;


        for(int i =0; i < s.size(); i++){
            // if(st.empty() && (s[i] == '{' || s[i] == '[' || s[i] = '(')) st.push(s[i]);
            if(st.empty() && (s[i] == '}' || s[i] == ']' || s[i] == ')')) return false;
            

            if(!st.empty()){
                if(s[i] == ')' && st.top() != '(') return false;
                else if(s[i] == ')' && st.top() == '(') st.pop();
                else if(s[i] == ']' && st.top() != '[') return false;
                else if(s[i] == ']' && st.top() == '[') st.pop();
                else if(s[i] =='}' && st.top()!='{') return false;
                else if(s[i] == '}' && st.top() == '{') st.pop();
            }
            if(s[i] == '{' || s[i] == '[' || s[i] == '(') st.push(s[i]);
        }

        if(!st.empty()) return false;

        return true;
    }
};