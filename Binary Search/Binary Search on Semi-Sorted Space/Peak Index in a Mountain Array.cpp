class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1, n = arr.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(mid > 0 && mid < n && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
            else if(mid > 0 && arr[mid] > arr[mid - 1]) low = mid;
            else high = mid;
        }
        return -1;
    }
};