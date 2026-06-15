class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, great;

        for(const int& it : nums) {
            if(it < pivot) less.push_back(it);
            else if(it == pivot) equal.push_back(it);
            else great.push_back(it);
        }

        less.insert(less.end(), equal.begin(), equal.end());
        less.insert(less.end(), great.begin(), great.end());

        return less;
    }
};