class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();

        stack<int> st;

        int j =0;
        for(int i = 0; i < n; i++){
            st.push(pushed[i]);

            while(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
        }

        while(!st.empty()){
            if(st.top() != popped[j]){
                return false;
            }
            st.pop();
            j++;
        }
        return true;
    }
};