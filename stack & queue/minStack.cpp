class MinStack {
public:
    stack<long long int> st;
    long long int minVal;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minVal = val;
        } else{
            if(val < minVal){
                st.push((long long)2*val - minVal);
                minVal = val;
            } else st.push(val);
        }
    }
    
    void pop() {
        if(st.top() < minVal) minVal = 2*minVal - st.top();
        st.pop();
    }
    
    int top() {
        if(st.top() < minVal) return minVal;
        else return st.top();
    }
    
    int getMin() {
        return minVal;
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