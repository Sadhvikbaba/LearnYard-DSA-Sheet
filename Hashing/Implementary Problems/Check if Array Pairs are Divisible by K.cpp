class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> count(k, 0);

        for(const int& it : arr) count[((it % k) + k) % k]++;

        if(count[0] & 1) return false;

        for(int i = 1; i <= k / 2; i++) {
            if(i == k - i) {
                if(count[i] % 2 != 0) return false;
            } else {
                if(count[i] != count[k - i]) return false;
            }
        }

        return true;    
    }
};