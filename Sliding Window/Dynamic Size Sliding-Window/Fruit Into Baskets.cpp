class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int cnt = 0, n = fruits.size();
        vector<int> count(n);
        int ans = 0;

        int right = 0, left = 0;

        while(right < n) {
            count[fruits[right]]++;
            if(count[fruits[right]] == 1) cnt++;

            while(cnt > 2) {
                if(count[fruits[left]] == 1) cnt--;
                count[fruits[left++]]--;
            }
            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};