class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(2, 0);
        unordered_set<int> st(nums2.begin(), nums2.end());

        for(int it : nums1){
            if(st.find(it) != st.end())ans[0]++;
        }

        st.clear();

        st.insert(nums1.begin(), nums1.end());

        for(int it : nums2){
            if(st.find(it) != st.end())ans[1]++;
        }

        return ans;
    }
};