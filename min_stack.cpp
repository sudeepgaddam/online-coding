class MinStack {
    
    private:
    stack<int> st;
    stack<int> min_st;
    
public:
    void push(int x) {
        if(st.empty() || (min_st.top() >= x)) {
            
            min_st.push(x);
        }
        st.push(x);
        
    }

    void pop() {
        
        if (min_st.top() == st.top() ){
            min_st.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        
        return min_st.top();
        
    }
};
