class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int base = 0, n = grumpy.size(), curr = 0;

        for(int i = 0; i < n; i++) {
            if(!grumpy[i]){
                base += customers[i];
                customers[i] = 0;
            }
        }
        int left = 0, right = 0;
        while(right < minutes) curr += customers[right++];
        int maxi = curr;

        while(right < n) {
            curr += customers[right++];
            curr -= customers[left++];

            maxi = max(maxi, curr);
        }

        return base + maxi;
    }
};