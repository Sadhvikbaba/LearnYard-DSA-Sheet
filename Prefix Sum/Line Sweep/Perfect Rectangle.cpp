class Solution {
private:
    bool func(long long key, unordered_set<long long>& st) {
        if(st.find(key) != st.end()) return true;
        return false;
    }

    void toggle(long long key, unordered_set<long long>& st) {
        auto it = st.find(key);
        if(it != st.end()) st.erase(it);
        else st.insert(key);
    }

    long long hash(int x, int y) {
        return ((long long)x << 32) | (unsigned int)y;
    }
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<long long> st;
        int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
        long long totalArea = 0, boundingArea = 0;

        for(const vector<int>& it : rectangles) {
            toggle(hash(it[0], it[1]), st);
            toggle(hash(it[2], it[3]), st);
            toggle(hash(it[0], it[3]), st);
            toggle(hash(it[2], it[1]), st);

            minX = min(minX, it[0]);
            minY = min(minY, it[1]);

            maxX = max(maxX, it[2]);
            maxY = max(maxY, it[3]);
            totalArea += 1ll * (it[2] - it[0]) * (it[3] - it[1]);
        }

        if(st.size() != 4) return false;

        boundingArea = 1ll * (maxX-minX)*(maxY-minY);

        if(boundingArea != totalArea) return false;

        if(!func(hash(minX, minY), st)) return false;
        if(!func(hash(minX, maxY), st)) return false;
        if(!func(hash(maxX, minY), st)) return false;
        if(!func(hash(maxX, maxY), st)) return false;
        
        return true;
    }
};