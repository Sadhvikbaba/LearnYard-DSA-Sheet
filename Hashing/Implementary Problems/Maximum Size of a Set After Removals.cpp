class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_set<int> st1(nums1.begin(), nums1.end()), st2(nums2.begin(), nums2.end());

        int common = 0;

        for(auto &it : st1) if(st2.count(it)) common++;

        int only1 = st1.size() - common;
        int only2 = st2.size() - common;

        int take1 = min(only1, n/2);
        int take2 = min(only2, n/2);

        int takeCommon = min(common, (n / 2 - take1) + (n / 2 - take2));

        return takeCommon + take1 + take2;
    }
};