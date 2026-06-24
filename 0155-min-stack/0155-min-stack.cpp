class MinStack {
stack<long long> st;
long long mini;
public:
    MinStack() {
        mini= LLONG_MAX;
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            mini = value;
        } else{
            if(mini > value){
                st.push(2LL*value - mini);
                mini = value;
            } else{
                st.push(value);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;

        if(mini > st.top()){
            mini = 2 * mini - st.top();
            st.pop();
        } else{
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()) return -1;

        long long x = st.top();
        if(mini < x){
            return x;
        }
         return mini;   
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */