class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<bool, bool>> check(10, {false, false});
        int min1 = nums1[0], min2 = nums2[0];

        for(int& it : nums1){ 
            min1 = min(min1, it);
            check[it].first = true;
        }

        for(int& it : nums2){
            min2 = min(min2, it);
            check[it].second = true;
        }

        for(int i = 1; i < 10; i++) if(check[i].first && check[i].second) return i;
        
        int a = min1 * 10 + min2, b = min2 * 10 + min1;
        return min(a, b);
    }
};