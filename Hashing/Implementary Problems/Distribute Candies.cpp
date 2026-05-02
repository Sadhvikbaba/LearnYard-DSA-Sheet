class Solution {
public:
    int distributeCandies(vector<int>& nums) {
        unordered_set<int> st;
        int limit = nums.size() / 2;

        for(int x : nums){
            st.insert(x);
            if(st.size() == limit) return limit;
        }

        return st.size();
    }
};