class MinStack {
    stack<int> st;
    stack<int> min_st;
public:
    MinStack() {
        
    }
    void push(int val) {
        st.push(val);
        if(min_st.empty()){
            min_st.push(val);
            return;
        }
        int temp = min(min_st.top(), val);
        min_st.push(temp);
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
