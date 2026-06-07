class NumArray {
    private:
        vector<int> arr;
public:
    NumArray(vector<int>& nums) {
        long long sum = 0;

        for(const int& it : nums) {
            sum += it;
            arr.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return arr[right];
        return arr[right] - arr[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */