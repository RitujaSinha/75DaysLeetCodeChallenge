class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        stack<char> st;

        string res = "";

        for(int i = 0; i < n; i++){
            while(!st.empty() && k > 0 && st.top()-'0' > num[i]-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // if(st.size() == num.size()){
            while(k--){
                st.pop();
            }
        // }

        if(st.empty()) return "0";

        while(!st.empty()){
            // if(res.empty() && st.top() == '0'){
            //     st.pop();
            //     continue;
            // }

            res += st.top();
            st.pop();
        }

        while(res.size() != 0 && res.back() == '0'){
            res.pop_back();
        }

        reverse(res.begin(), res.end());

        if(res.empty()) return "0";
        return res;
    }
};