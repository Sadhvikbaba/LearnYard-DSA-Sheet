class DinnerPlates {
private:
    vector<vector<int>> stacks;
    set<int> empty;
    int size;

    void trim() {
        while(!stacks.empty() && stacks.back().empty()) {
            empty.erase(stacks.size() - 1);
            stacks.pop_back();
        }
    }
public:
    DinnerPlates(int capacity) : size(capacity) { }
    
    void push(int val) {
        while(!empty.empty()) {
            auto it = empty.begin();
            int idx = *it;

            if(idx >= stacks.size()) empty.erase(it);
            else if(stacks[idx].size() == size) empty.erase(it);
            else break;
        }

        if(empty.empty()) {
            stacks.emplace_back();
            empty.insert(stacks.size() -1);
        }

        int idx = *empty.begin();
        stacks[idx].push_back(val);

        if(stacks[idx].size() == size) empty.erase(idx);
    }
    
    int pop() {
        trim();

        if(stacks.empty()) return -1;

        int idx = stacks.size() - 1;
        int value = stacks[idx].back();
        stacks[idx].pop_back();

        empty.insert(idx);

        trim();

        return value;
    }
    
    int popAtStack(int index) {
        if(stacks.size() <= index) return -1;
        if(stacks[index].empty()) return -1;

        int value = stacks[index].back();

        stacks[index].pop_back();

        empty.insert(index);

        return value;
    }
};
/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */