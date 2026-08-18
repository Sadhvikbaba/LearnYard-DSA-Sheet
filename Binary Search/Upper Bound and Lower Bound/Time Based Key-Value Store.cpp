class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> mpp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto temp = mpp.find(key);

        if(temp == mpp.end()) return "";
        auto &it = temp -> second;

        int low = 0, high = it.size() - 1;
        string ans = "";

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(it[mid].first <= timestamp) {
                ans = it[mid].second;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */