class FreqStack {
private:
    int maxFreq;
    unordered_map<int , int> freq;
    unordered_map<int, stack<int>> mpp;
public:
    FreqStack() : maxFreq(0) {
        freq.reserve(20000);
        mpp.reserve(20000);
    }
    
    void push(int val) {
        int temp = ++freq[val];

        mpp[temp].push(val);

        if(temp > maxFreq) maxFreq = temp;
    }
    
    int pop() {
        auto &it = mpp[maxFreq];

        int value = it.top();
        it.pop();

        if(--freq[value] == 0)freq.erase(value);

        if(mpp[maxFreq].empty()) {
            mpp.erase(maxFreq);
            maxFreq--;
        }
        return value;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */