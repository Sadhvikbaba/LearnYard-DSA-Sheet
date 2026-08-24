#include<algorithm>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 , n = piles.size();
        int high = *max_element(piles.begin() , piles.end());
        while(low <= high){
            int mid = (low + high) / 2;

            long long totalH = 0;
            for(const int pile : piles){
                totalH += (pile + mid - 1) / mid ;
            }

            if(totalH <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};