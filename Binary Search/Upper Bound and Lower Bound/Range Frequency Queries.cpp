class RangeFreqQuery {
    unordered_map<int, vector<int>> mpp;
public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++) mpp[arr[i]].emplace_back(i);
    }
    
    int query(int left, int right, int value) {
        auto temp = mpp.find(value);
        if(temp == mpp.end()) return 0;

        vector<int>&arr = temp -> second;

        int l = lower_bound(arr.begin(), arr.end(), left) - arr.begin();
        int r = upper_bound(arr.begin(), arr.end(), right) - arr.begin();

        return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */