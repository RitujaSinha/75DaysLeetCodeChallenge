class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else{
        if(val < mini){
            st.push(2LL * val-mini);
            mini=val;
        } else{
            st.push(val);
        }
        }
    }
    
    void pop() {
        if(st.empty()) return;

        long long top = st.top();
        st.pop();

        if(top < mini){
            mini = 2*mini-top;
        }
    }
    
    int top() {
        if(st.empty()) return -1;

        long long top = st.top();
        
        if(top < mini){
            return mini;
        } 
        return st.top();
    }
    
    int getMin() {
        if(st.empty()) return -1;

        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */