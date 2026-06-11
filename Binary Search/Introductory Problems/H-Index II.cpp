class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 0, high = citations.size();
        int ans = 0, n = high;  

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(citations[mid] >= n - mid) {
                ans = max(ans, n - mid);
                high = mid;
            } else low = mid + 1;
        }
        return ans;
    }
};