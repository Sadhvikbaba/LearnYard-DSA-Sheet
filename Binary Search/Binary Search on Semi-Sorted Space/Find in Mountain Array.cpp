/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
int findPeak(MountainArray& arr) {
    int low = 0, high = arr.length() - 1;

    while(low < high) {
        int mid = low + (high - low) / 2;

        if(arr.get(mid) < arr.get(mid + 1)) low = mid + 1;
        else high = mid;
    }

    return low;
}

int findInc(MountainArray& arr, int low, int high, int target) {
    while(low <= high) {
        int mid = low + (high - low) / 2;

        int value = arr.get(mid);

        if(target == value) return mid;
        if(value < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int findDec(MountainArray& arr, int low, int high, int target) {
    while(low <= high) {
        int mid = low + (high - low) / 2;

        int value = arr.get(mid);

        if(target == value) return mid;
        if(value < target) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

public:
    int findInMountainArray(int target, MountainArray &arr) {
        int peak = findPeak(arr);
        
        int ind = findInc(arr, 0, peak, target);

        if(ind != -1) return ind;

        return findDec(arr, peak + 1, arr.length() - 1, target);
    }
};