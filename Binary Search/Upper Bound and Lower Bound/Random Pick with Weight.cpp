class Solution {
vector<int> prefix;
int total;
public:
    Solution(vector<int>& w) {
        total = 0;

        for(const int& it : w) {
            total += it;
            prefix.push_back(total);
        }
    }
    
    int pickIndex() {
        int target = rand() % total + 1;

        int ind = lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();

        return ind;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */