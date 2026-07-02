class CustomStack {
private:
    vector<int> st;
    int maxSize;
public:
    CustomStack(int maxSize) : maxSize(maxSize) {
        
    }
    
    void push(int x) {
        if(st.size() == maxSize) return;

        st.push_back(x);
    }
    
    int pop() {
        if(st.size() == 0) return -1;
        int temp = st.back();
        st.pop_back();
        return temp;
    }
    
    void increment(int k, int val) {
        int end = min((int)st.size(), k);

        for(int i = 0; i < end; i++) st[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */