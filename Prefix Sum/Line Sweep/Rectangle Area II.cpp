class Solution {
private:
    static constexpr long long MOD = 1e9 + 7;

    void addInterval(vector<vector<int>>& events, int x1, int y1, int y2) {
        events.push_back({x1, y1, y2, 1});
    }

    void removeInterval(vector<vector<int>>& events, int x1, int y1, int y2) {
        events.push_back({x1, y1, y2, -1});
    }

    long long getYLength(vector<pair<int, int>>& active) {
        if(active.empty()) return 0;

        sort(active.begin(), active.end());

        long long len = 0;
        int start = active[0].first, end = active[0].second, n =active.size();

        for(int i = 1; i < n; i++) {
            if(active[i].first <= end) end = max(end, active[i].second);
            else {
                len += end - start;
                start = active[i].first;
                end = active[i].second;
            }
        }
        len += end - start;

        return len;
    }
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<vector<int>> events;

        for(const vector<int>& it : rectangles) {
            addInterval(events, it[0], it[1], it[3]);
            removeInterval(events, it[2], it[1], it[3]);
        }
        int n = events.size() - 1;

        sort(events.begin(), events.end());

        long long ans = 0, prevX = events[0][0];
        vector<pair<int, int>> active;

        for(const auto& it : events) {
            long long width = it[0] - prevX;
            long long height = getYLength(active);

            ans = (ans + width * height) % MOD;

            if(it[3] == 1) active.push_back({it[1], it[2]});
            else {
                for(auto i = active.begin(); i != active.end(); i++) {
                    if(*i == make_pair(it[1], it[2])) {
                        active.erase(i);
                        break;
                    }
                }
            }
            prevX = it[0];
        }
        return ans % MOD;
    }
};