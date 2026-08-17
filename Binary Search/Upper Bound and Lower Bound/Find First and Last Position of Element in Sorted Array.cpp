class Solution {
private:
    int firstOcc(vector<int> &nums , int x , int high) {
        int low = 0 , first = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == x){
                first = mid;
                high = mid - 1;
            }else if(nums[mid] < x)low = mid + 1;
            else high = mid - 1;
        }
        return first;
    }
    int lastOcc(vector<int> &nums , int x , int high) {
        int low = 0 , last = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == x){
                last = mid;
                low = mid + 1;
            }else if(nums[mid] < x)low = mid + 1;
            else high = mid - 1;
        }
        return last;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        int first = firstOcc(nums , target , n);
        if(first == -1) return {-1 , -1};
        return { first , lastOcc(nums , target , n)};
    }
};