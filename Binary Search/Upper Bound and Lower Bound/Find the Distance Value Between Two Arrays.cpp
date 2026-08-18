class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans = 0;

        for(const int& it : arr1) {
            auto val = lower_bound(arr2.begin(), arr2.end(), it);

            if(val != arr2.end() && abs(it - *val) <= d) continue;
            if(val != arr2.begin() && abs(*prev(val) - it) <= d) continue;

            ans++;
        }
        return ans;
    }
};