class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mpp;
        int n = cards.size(), left = 0, right = 0, ans = INT_MAX;

        for(int right = 0; right < n; right++) {
            auto it = mpp.find(cards[right]);

            if(it != mpp.end()) {
                ans = min(ans, right - it -> second  + 1);
                it -> second = right;
            } else mpp[cards[right]] = right;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};