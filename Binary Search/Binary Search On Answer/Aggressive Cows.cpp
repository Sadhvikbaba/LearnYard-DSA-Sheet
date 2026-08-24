class Solution {
    
    bool isPossible(vector<int>& arr, int dist, int req) {
        int cnt = 1, last = arr[0], n = arr.size();
        
        for(int i = 1; i < n; i++) {
            if(arr[i] - last >= dist) {
                cnt++;
                last = arr[i];
            }
            if(cnt >= req) return true;
        }
        return false;
    }
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int low = 0, high = arr[n - 1] - arr[0];
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(isPossible(arr, mid, k)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};