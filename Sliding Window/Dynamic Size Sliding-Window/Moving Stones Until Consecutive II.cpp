class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());
        int maxi = max(stones[n - 1] - stones[1] - n + 2,
                        stones[n - 2] - stones[0] - n + 2 );

        int mini = n;

        for(int left = 0, right = 0; right < n; right++) {
            while(stones[right] - stones[left] >= n) left++;

            int inside = right - left + 1;
            if(inside == n - 1 && stones[right] - stones[left] == n - 2) mini = min(mini, 2);
            else mini = min(mini, n - inside);
        }

        return {mini, maxi};
    }
};